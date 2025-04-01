package com.flocto.notsus;

import org.bukkit.command.*;
import org.bukkit.entity.*;

class PingCommand implements CommandExecutor {
    public boolean onCommand(final CommandSender commandSender, final Command command, final String label, final String[] args) {
        if (commandSender instanceof Player) {
            final Player player = (Player)commandSender;
            int ping = player.getPing();
            commandSender.sendMessage("Pong! Your ping is " + ping + "ms");
            return true;
        }
        commandSender.sendMessage("Pong!");
        return false;
    }
}
