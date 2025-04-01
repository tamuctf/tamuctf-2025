#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <crypt.h>
#include <pwd.h>
#include <shadow.h>
#include <grp.h>

#define USERNAME_LEN 16
#define PASSWORD_LEN 32

#define TRY_AGAIN(CALLBACK) \
    do { \
        ungetc('\n', stdin); \
        CALLBACK(); \
        return; \
    } while (0)

#define GET_INPUT(BUF, CALLBACK) \
    do { \
        if (fgets(BUF, sizeof(BUF), stdin) == NULL) { \
            fprintf(stderr, "Error reading user input.\n\n"); \
            TRY_AGAIN(CALLBACK); \
        } \
        BUF[strcspn(BUF, "\n")] = 0; \
    } while (0)

void menu();

void gen_salt(char *salt, size_t size) {
    const char *salt_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";
    srand(time(NULL));

    salt[0] = '$';
    salt[1] = '6';
    salt[2] = '$';  

    for (size_t i = 3; i < size - 1; i++)
        salt[i] = salt_chars[rand() % 64];
    salt[size - 1] = '\0';
}

void login() {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];

    while (getchar() != '\n');

    printf("Username (%d): ", USERNAME_LEN);
    GET_INPUT(username, login);

    printf("Password (%d): ", PASSWORD_LEN);
    GET_INPUT(password, login);

    struct passwd *pw = getpwnam(username);
    if (!pw) {
        fprintf(stderr, "User not found!\n\n");
        TRY_AGAIN(menu);
    }

    struct spwd *sp = getspnam(username);
    if (!sp) {
        fprintf(stderr, "Shadow entry not found!\n");
        exit(1);
    }

    char *hash = crypt(password, sp->sp_pwdp);
    if (!hash || strcmp(hash, sp->sp_pwdp) != 0) {
        fprintf(stderr, "Authentication failed\n\n");
        TRY_AGAIN(login);
    }

    printf("\nEntering sandbox...\n");
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (setgid(pw->pw_gid) != 0) {
            perror("setgid");
            exit(1);
        }
        if (initgroups(username, pw->pw_gid) != 0) {
            perror("initgroups");
            exit(1);
        }
        if (setuid(pw->pw_uid) != 0) {
            perror("setuid");
            exit(1);
        }
    
        setenv("HOME", pw->pw_dir, 1);
        setenv("USER", pw->pw_name, 1);
        setenv("SHELL", pw->pw_shell, 1);
        chdir(pw->pw_dir);
        
        printf("You can start executing Bash commands now.\n");
        execl("/bin/bash", "bash", "-l", NULL);
        perror("execl failed");
        exit(1);
    } else {
        wait(NULL);
        printf("\n");
        TRY_AGAIN(menu);
    }
}

void create_account() {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    char confirm_password[PASSWORD_LEN];

    while (getchar() != '\n');

    printf("Username (%d): ", USERNAME_LEN);
    GET_INPUT(username, create_account);
    
    printf("Password (%d): ", PASSWORD_LEN);
    GET_INPUT(password, create_account);

    printf("Confirm password (%d): ", PASSWORD_LEN);
    GET_INPUT(confirm_password, create_account);

    if (strcmp(password, confirm_password) != 0) {
        fprintf(stderr, "Passwords do not match!\n\n");
        TRY_AGAIN(create_account);
    }

    char salt[20];
    gen_salt(salt, sizeof(salt));
    char *hash = crypt(password, salt);
    if (!hash) {
        perror("crypt");
        exit(1);
    }

    pid_t pid = fork();
    if (pid == 0) {
        execlp("useradd", "useradd", "-m", "-p", hash, username, NULL);
        perror("execlp");
        exit(1);
    }

    int status;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
        printf("\n");
        TRY_AGAIN(menu);
    }

    printf("Account registered!\n\n");
}

void menu() {
    char *options = "Welcome to the Sandbox.\n"
                    "Please select an option.\n"
                    "1. Login as existing user\n"
                    "2. Register an account\n"
                    "3. Exit\n"
                    "Choice (1-3): ";

    while (getchar() != '\n');

    while (1) {
        printf("%s", options);
        char choice = getchar();
    
        switch (choice) {
            case '1':
                login();
                break;
            case '2':
                create_account();
                break;
            case '3':
                printf("Exiting!\n");
                exit(0);
            default:
                fprintf(stderr, "Invalid option!\n\n");
                menu();
        }
    }
}

int main(int argc, char *argv[]) {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    ungetc('\n', stdin);
    menu();
    return 0;
}
