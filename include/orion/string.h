#ifndef __LIB_STRING_H
#define __LIB_STRING_H

#include <orion/stdint.h>

void reverse(char*);
size_t strlen(char*);

void *memcpy(void*, const void*, size_t);
void *memset(void*, int32_t, size_t);
void *memmove(void*, const void*, size_t);
int32_t memcmp(const void *, const void*, size_t);

#endif //  __LIB_STRING_H