;;boot.asm

;nasm directive - 32 bit
bits 32

%define MULTIBOOT2_MAGIC           0xE85250D6
%define MULTIBOOT2_ARCH            0
%define MULTIBOOT2_HEADER_LENGTH   24
%define MULTIBOOT2_CHECKSUM        (-(MULTIBOOT2_MAGIC + MULTIBOOT2_ARCH + MULTIBOOT2_HEADER_LENGTH))

section .multiboot align=8
	; magic number
	dd MULTIBOOT2_MAGIC ; dd 0xe85250d6 ; multiboot2
	; architecture
	dd MULTIBOOT2_ARCH ; dd 0 ; protected mode i386
	; header length
	dd MULTIBOOT2_HEADER_LENGTH ; dd header_end - header_start
	; checksum
	dd MULTIBOOT2_CHECKSUM ; dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))

	; end tag
	; dw 0
	; dw 0
	dd 0
	dd 8

  
section .text

global _start
extern kmain	        ;kmain is defined in the c file

_start:
  cli 			;block interrupts
  mov esp, stack_space	;set stack pointer
  push ebx
  push eax
  call kmain
  hlt		 	;halt the CPU

message:
	db "Booting Kernel...", 0

section .bss
resb 8192		;8KB for stack
stack_space: