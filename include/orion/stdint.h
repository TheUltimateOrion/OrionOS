#ifndef __STDINT_H
#define __STDINT_H

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef long unsigned int uint64_t;

typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long int int64_t;

typedef unsigned long int size_t;

void itoa(int n, char *str);

#endif