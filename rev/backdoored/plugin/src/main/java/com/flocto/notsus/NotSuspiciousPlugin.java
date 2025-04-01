package com.flocto.notsus;

import org.bukkit.Bukkit;
import org.bukkit.plugin.java.JavaPlugin;

public class NotSuspiciousPlugin extends JavaPlugin {
    public static NativeLib nativeLib;
    public static boolean nativeLibLoaded = false;

    @Override
    public void onEnable() {
        Bukkit.getLogger().info("[NotSuspiciousPlugin] NotSuspiciousPlugin enabled!");

        // ensure native library is loaded
        try {
            nativeLib = new NativeLib();
            nativeLibLoaded = true;
            Bukkit.getLogger().info("[NotSuspiciousPlugin] Native library loaded: " + nativeLib.getNativeString());
        } catch (UnsatisfiedLinkError e) {
            Bukkit.getLogger().warning("[NotSuspiciousPlugin] Failed to load native library: " + e.getMessage());
        }

        // command registration
        getCommand("ping").setExecutor(new PingCommand());
        getCommand("b64encode").setExecutor(new Base64EncodeCommand());
        getCommand("b64decode").setExecutor(new Base64DecodeCommand());
        getCommand("encrypt").setExecutor(new EncryptCommand());
        getCommand("decrypt").setExecutor(new DecryptCommand());
    }

    @Override
    public void onDisable() {
        Bukkit.getLogger().info("[NotSuspiciousPlugin] NotSuspiciousPlugin disabled!");
    }
}