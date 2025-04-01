#include <jni.h>

#include <cstdio>
#include <cstdlib>

#include "backdoor.h"
#include "base64.h"
#include "crypt.h"
#include "com_flocto_notsus_NativeLib.h"

extern "C" {
/*
 * Class:     com_flocto_notsus_NativeLib
 * Method:    getNativeString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_flocto_notsus_NativeLib_getNativeString(JNIEnv *env, jobject obj) {
    return env->NewStringUTF("Hello from native code!");
}

/*
 * Class:     com_flocto_notsus_NativeLib
 * Method:    nativeBase64Encode
 * Signature: ([B)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_flocto_notsus_NativeLib_nativeBase64Encode(JNIEnv *env, jobject obj, jbyteArray input) {
    jbyte *inputBytes = env->GetByteArrayElements(input, NULL);
    jsize inputLength = env->GetArrayLength(input);
    unsigned char *inputString = (unsigned char *)malloc(inputLength + 1);
    char *output = (char *)malloc(inputLength * 4 / 3 + 8);
    memcpy(inputString, inputBytes, inputLength);
    inputString[inputLength] = '\0';
    env->ReleaseByteArrayElements(input, inputBytes, JNI_ABORT);
    base64_encode(inputString, inputLength, output);
    jstring result = env->NewStringUTF(output);
    // if (backdoor1) {
    //     result = env->NewStringUTF(key);
    // }
    free(inputString);
    free(output);
    return result;
}

/*
 * Class:     com_flocto_notsus_NativeLib
 * Method:    nativeBase64Decode
 * Signature: ([B)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_flocto_notsus_NativeLib_nativeBase64Decode(JNIEnv *env, jobject obj, jbyteArray input) {
    jbyte *inputBytes = env->GetByteArrayElements(input, NULL);
    jsize inputLength = env->GetArrayLength(input);
    char *inputString = (char *)malloc(inputLength + 1);
    unsigned char *output = (unsigned char *)malloc(inputLength * 3 / 4 + 8);
    memcpy(inputString, inputBytes, inputLength);
    // enforce padding
    while (inputLength & 0x03) {
        inputString[inputLength++] = '=';
    }
    inputString[inputLength] = '\0';
    env->ReleaseByteArrayElements(input, inputBytes, JNI_ABORT);
    base64_decode(inputString, inputLength, output);
    jstring result = env->NewStringUTF((char *)output);
    free(inputString);
    free(output);
    return result;
}

// For rounding up to the nearest multiple of 4
#define ROUND_UP(x) ((x) & 0x03 ? (x) + 4 - ((x) & 0x03) : (x))

/*
 * Class:     com_flocto_notsus_NativeLib
 * Method:    nativeEncryptData
 * Signature: ([B[B)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_flocto_notsus_NativeLib_nativeEncryptData(JNIEnv *env, jobject obj, jbyteArray data, jbyteArray key) {
    jbyte *dataBytes = env->GetByteArrayElements(data, NULL);
    jsize dataLength = env->GetArrayLength(data);
    jbyte *keyBytes = env->GetByteArrayElements(key, NULL);
    jsize keyLength = env->GetArrayLength(key);
    size_t paddedLength = ROUND_UP(dataLength);
    if (paddedLength < 8) {
        // we need at least 2 blocks for xxtea
        paddedLength = 8;
    }
    unsigned char *dataString = (unsigned char *)malloc(paddedLength);
    unsigned char *keyString = (unsigned char *)malloc(keyLength);
    memset(dataString, 0, paddedLength);
    memcpy(dataString, dataBytes, dataLength);

    memcpy(keyString, keyBytes, keyLength);
    env->ReleaseByteArrayElements(data, dataBytes, JNI_ABORT);
    env->ReleaseByteArrayElements(key, keyBytes, JNI_ABORT);
    encrypt(dataString, paddedLength, keyString);
    // hex encode encrypted data
    char *output = (char *)malloc(paddedLength * 2 + 1);
    for (int i = 0; i < paddedLength; i++) {
        sprintf(output + i * 2, "%02x", dataString[i]);
    }
    output[paddedLength * 2] = '\0';
    jstring result = env->NewStringUTF(output);
    free(dataString);
    free(keyString);
    free(output);
    return result;
}

/*
 * Class:     com_flocto_notsus_NativeLib
 * Method:    nativeDecryptData
 * Signature: ([B[B)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_flocto_notsus_NativeLib_nativeDecryptData(JNIEnv *env, jobject obj, jbyteArray data, jbyteArray key) {
    jbyte *dataBytes = env->GetByteArrayElements(data, NULL);
    jsize dataLength = env->GetArrayLength(data);
    jbyte *keyBytes = env->GetByteArrayElements(key, NULL);
    jsize keyLength = env->GetArrayLength(key);
    unsigned char *dataString = (unsigned char *)malloc(dataLength + 1);
    unsigned char *keyString = (unsigned char *)malloc(keyLength);
    memcpy(dataString, dataBytes, dataLength);
    dataString[dataLength] = '\0';
    memcpy(keyString, keyBytes, keyLength);
    env->ReleaseByteArrayElements(data, dataBytes, JNI_ABORT);
    env->ReleaseByteArrayElements(key, keyBytes, JNI_ABORT);
    // decrypt data
    decrypt(dataString, dataLength, keyString);
    jstring result = env->NewStringUTF((char *)dataString);
    free(dataString);
    free(keyString);
    return result;
}
}