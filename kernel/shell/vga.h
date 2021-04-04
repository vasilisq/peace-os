#ifndef _VGA_H_
#define _VGA_H_
#include <stdint.h>
#include <stddef.h>

void vga_text_init(void);
void vga_text_setcolor(uint8_t color);
void vga_text_write(const char* data, size_t size);
void vga_reset_caret(void);
#endif