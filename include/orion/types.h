#ifndef __TYPES_H
#define __TYPES_H

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef long unsigned int uint64_t;

typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long int int64_t;

typedef unsigned long int size_t;

typedef unsigned char bool;
#define false 0
#define true 1

void itoa(int n, char *str);

void reverse(char*);
size_t strlen(char*);

void *memcpy(void*, const void*, size_t);
void *memset(void*, int32_t, size_t);
void *memmove(void*, const void*, size_t);
int32_t memcmp(const void *, const void*, size_t);

#define FASTCALL __attribute__((fastcall))

#endif // __TYPES_H