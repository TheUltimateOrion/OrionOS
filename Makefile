SRC_DIR   := src
INCLUDE_DIR := include
OBJ_DIR := obj
OUT_DIR := out

AS := nasm
ASFLAGS := -f elf32 -o

CC := gcc
CCFLAGS := -m32 -c -ffreestanding -fno-builtin -funsigned-char -O2 -nostdlib -fdiagnostics-color=auto -fdiagnostics-show-option \
-Wall -Wextra -Werror -Wpedantic -Wconversion -Wsign-conversion -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wundef \
-Wredundant-decls -Wmissing-prototypes -Wstack-usage=1024 -g3 -ggdb -nostdinc -o

LD := ld
LDFLAGS := -m elf_i386 -T link.ld -o

GRUBISO := grub-mkrescue
GRUBFLAGS := -o

SRCS := $(shell find $(SRC_DIR) -name '*.c') $(shell find $(SRC_DIR) -name '*.asm')
OBJS :=  $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(patsubst $(SRC_DIR)/%.asm, $(OBJ_DIR)/%.o, $(SRCS)))
BOOT := $(SRC_DIR)/boot/boot.asm
BIN := iso/boot/kernel.bin

all: $(OBJS) $(BIN)

image: $(BIN)
	$(GRUBISO) $(GRUBFLAGS) $(OUT_DIR)/bootable.iso iso

$(BIN): $(OBJS) | $(OBJ_DIR)
	$(LD) $(LDFLAGS) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.asm | $(OBJ_DIR)
	$(AS) $(ASFLAGS) $@ $<  
 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CCFLAGS) $@ -I $(INCLUDE_DIR) $<

$(OBJ_DIR):
	mkdir -p $(subst $(SRC_DIR), $(OBJ_DIR), $(dir $(SRCS)))
	mkdir -p $(OUT_DIR)

# -include $(OBJ_DIR)/*.d
clean:
	@echo $(OBJS)
	rm -rf $(OBJ_DIR)
	rm -rf $(OUT_DIR)
	rm -rf $(BIN)
	rm -rf $(OUT_DIR)/bootable.iso