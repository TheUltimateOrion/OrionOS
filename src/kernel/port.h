#ifndef __PORT_H
#define __PORT_H

void outb(unsigned short port, unsigned char val);
unsigned char inb(unsigned short port);

#endif