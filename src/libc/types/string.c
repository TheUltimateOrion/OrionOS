#include "string.h"

uint32_t strlen(char *str) {
    uint32_t len = 0;
    while (*str != '\0') {
        str++;
        len++;
    }
    return len;
}

void reverse(char* str) {
    uint32_t l = 0;
    uint32_t r = strlen(str) - 1;
    char t;

    while (l < r) {
        t = str[l];
        str[l] = str[r];
        str[r] = t;

        l++;
        r--;
    }
}