#ifndef __ARCH_x86_H
#define __ARCH_x86_H

#include <orion/types.h>

struct gdt_entry_t {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));

#endif // __ARCH_x86_H
