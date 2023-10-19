cmake_minimum_required(VERSION 3.4.1)

add_library(
        openssl-wrapper SHARED
        openssl-wrapper.cpp
)

add_library(lib_crypto STATIC IMPORTED)
set_target_properties(lib_crypto PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/${ANDROID_ABI}/libs/libcrypto.a)

add_library(lib_ssl STATIC IMPORTED)
set_target_properties(lib_ssl PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/${ANDROID_ABI}/libs/libssl.a)

include_directories(${CMAKE_SOURCE_DIR}/${ANDROID_ABI}/include)

target_link_libraries(
        openssl-wrapper
        lib_crypto
        lib_ssl
        log
)