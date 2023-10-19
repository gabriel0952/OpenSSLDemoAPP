package com.example.openssldemoapp;

public class OpenSSLHelp {
   static {
      System.loadLibrary("openssl-wrapper");
   }

   public static native String stringFromJNI();

   public static native String stringFromMD5(String data);
}
