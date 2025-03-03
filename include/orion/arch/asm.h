#ifndef __ASM_H
#define __ASM_H

#include <orion/types.h>

static inline void outb(uint16_t port, uint8_t val) {
    __asm__ volatile ("outb %0, %1" : : "a"(val), "Nd"(port):);
}

static inline uint8_t inb(uint16_t port) {
    uint8_t returnVal;
    __asm__ volatile ("inb %1, %0"
    : "=a"(returnVal)
    : "Nd"(port));
    return returnVal;
}

static inline void halt(void) {
    __asm__ volatile ("hlt":::);
}

#endif // __ASM_H