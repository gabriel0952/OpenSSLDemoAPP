#include <jni.h>
#include <stdio.h>
#include <string.h>
#include <android/log.h>
#include "openssl/md5.h"

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "E2EE IM", __VA_ARGS__)

extern "C" {

    JNIEXPORT jstring JNICALL Java_com_example_openssldemoapp_OpenSSLHelp_stringFromJNI(JNIEnv *env, jclass clazz) {
        return env->NewStringUTF("Hello from JNI");
    }

    JNIEXPORT jstring JNICALL Java_com_example_openssldemoapp_OpenSSLHelp_stringFromMD5(JNIEnv *env, jclass clazz, jstring srcjStr) {
        const char *unicodeChar = env->GetStringUTFChars(srcjStr, NULL);
        size_t unicodeCharLength = env->GetStringLength(srcjStr);

        LOGD("stringFromMD5( %s ) = %d", unicodeChar, unicodeCharLength);

        unsigned char md[MD5_DIGEST_LENGTH];
        int i;
        char buf[33] = {'\0'};
        MD5((unsigned char*)unicodeChar, unicodeCharLength, (unsigned char*)&md);
        for (i = 0; i < 16; i++) {
            sprintf(&buf[i*2], "%02x", md[i]);
        }
        env->ReleaseStringUTFChars(srcjStr, unicodeChar);
        return env->NewStringUTF(buf);
    }

}