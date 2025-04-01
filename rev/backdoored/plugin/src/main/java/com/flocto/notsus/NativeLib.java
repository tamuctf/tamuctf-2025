package com.flocto.notsus;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;

class NativeLib {
    public native String getNativeString();

    public native String nativeBase64Encode(byte[] input);
    public native String nativeBase64Decode(byte[] input);

    // public native String nativeMD5Hash(byte[] input);
    // public native String nativeSha1Hash(byte[] input);
    // public native String nativeSha256Hash(byte[] input);

    public native String nativeEncryptData(byte[] plaintext, byte[] key);
    public native String nativeDecryptData(byte[] ciphertext, byte[] key);

    NativeLib() {
        try {
            // String pluginDir = new File(getClass().getProtectionDomain().getCodeSource().getLocation().toURI()).getParent();  
            // String nativeLibPath = pluginDir + "/notsuspicious.so";  
            
            // unpack notsuspicious.so from jar resources
            InputStream in = getClass().getResourceAsStream("/notsuspicious.so");
            if (in == null) {
                throw new FileNotFoundException("Failed to find native library in jar resources.");
            }

            File tempFile = File.createTempFile("notsuspicious", ".so");
            tempFile.deleteOnExit();

            Files.copy(in, tempFile.toPath(), java.nio.file.StandardCopyOption.REPLACE_EXISTING);
            System.load(tempFile.getAbsolutePath());
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (UnsatisfiedLinkError e) {
            e.printStackTrace();
        }
    }
}
