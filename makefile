CC			= gcc
# todo: provide custom libc instead of gcc's here
CCFLAGS 	= -m32 -Wall -Werror -fno-builtin -nostdinc -nostdlib -ffreestanding -Wextra -I '/usr/lib/gcc/x86_64-alpine-linux-musl/10.2.1/include'
ASFLAGS 	= --32
LDFLAGS 	= -melf_i386 -nostdlib
LD      	= ld
OBJFILES 	= kernel/boot.o  \
	kernel/kernel.o \
	kernel/shell/shell.o \
	kernel/shell/vga.o
BUILD_DIR = build
OUTPUT = $(BUILD_DIR)/kernel.bin
IMAGE = $(BUILD_DIR)/kernel.iso

all: $(OUTPUT) check-boot
rebuild: clean all
dev-all: clean all image
.s.o:
	as $(ASFLAGS) -o $@ $<
.c.o:
	$(CC) $(CCFLAGS) -o $@ -c $<
$(OUTPUT): $(OBJFILES)
	$(LD) $(LDFLAGS) -T linker.ld -o $@ $^
check-boot:
	grub-file --is-x86-multiboot $(OUTPUT)

clean:
	rm -f $(BUILD_DIR)/* $(OBJFILES)

image: $(IMAGE)
$(IMAGE):
	mkdir -p iso/boot/grub
	cp $(OUTPUT) ./iso/boot
	cp grub.cfg ./iso/boot/grub/
	grub-mkrescue --output="$(IMAGE)" ./iso
	rm -rf iso

docker-build:
	docker-compose -f docker/docker-compose.yaml up

run:
	qemu-system-i386 -cdrom $(IMAGE)