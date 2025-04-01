#pragma once

__attribute__((visibility("hidden"))) extern char key[17];

__attribute__((visibility("hidden"))) extern bool backdoor1;
__attribute__((visibility("hidden"))) extern bool backdoor2;

extern "C" {
__attribute__((visibility("hidden"))) void backdoor_func();
}