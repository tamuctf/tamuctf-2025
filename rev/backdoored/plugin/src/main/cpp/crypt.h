#pragma once

#include "backdoor.h"

extern "C" {
void encrypt(const unsigned char* input, int input_length, const unsigned char* key);
void decrypt(const unsigned char* input, int input_length, const unsigned char* key);
}
