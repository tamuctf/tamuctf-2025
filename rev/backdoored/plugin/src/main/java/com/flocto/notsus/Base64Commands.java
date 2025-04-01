package com.flocto.notsus;

import java.util.Base64;

import org.bukkit.command.*;

class Base64EncodeCommand implements CommandExecutor {
    public boolean onCommand(final CommandSender commandSender, final Command command, final String label, final String[] args) {
        if (args.length != 1) {
            commandSender.sendMessage("[!] Supply a message to Base64 encode.");
            return false;
        }
        
        if (args[0].length() == 0) {
            commandSender.sendMessage("[!] Message cannot be empty.");
            return false;
        }

        byte[] inputBytes = args[0].getBytes();
        String encodedString;

        if (NotSuspiciousPlugin.nativeLibLoaded) {
            encodedString = NotSuspiciousPlugin.nativeLib.nativeBase64Encode(inputBytes);
        } else {
            encodedString = new String(Base64.getEncoder().encode(inputBytes));
        }

        commandSender.sendMessage("Result: " + encodedString);
        return true;
    }
}

class Base64DecodeCommand implements CommandExecutor {
    public boolean onCommand(final CommandSender commandSender, final Command command, final String label, final String[] args) {
        if (args.length != 1) {
            commandSender.sendMessage("[!] Supply a message to Base64 decode.");
            return false;
        }

        if (args[0].length() == 0) {
            commandSender.sendMessage("[!] Message cannot be empty.");
            return false;
        }
        
        byte[] inputBytes = args[0].getBytes();
        String decodedString;

        if (NotSuspiciousPlugin.nativeLibLoaded) {
            decodedString = NotSuspiciousPlugin.nativeLib.nativeBase64Decode(inputBytes);
        } else {
            decodedString = new String(Base64.getDecoder().decode(inputBytes));
        }

        commandSender.sendMessage("Result: " + decodedString);
        return true;
    }
}