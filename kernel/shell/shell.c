#include "shell.h"
#include "vga.h"

static uint8_t CURRENT_SHELL_MODE = SHELL_MODE_NONE;

/* todo: move to string.h */
size_t strlen(const char *str) {
    uint32_t len = 0;
    while (str[len]) len++;
    return len;
}

void shell_init(enum shell_mode mode) {
    if (mode == SHELL_MODE_VGA) {
        vga_text_init();
    }
    CURRENT_SHELL_MODE = mode;
}

void shell_set_text_color(enum shell_text_color color) {
    if (CURRENT_SHELL_MODE == SHELL_MODE_VGA) {
        vga_text_setcolor(color);
    }
}

void shell_write(const char *str) {
    if (CURRENT_SHELL_MODE == SHELL_MODE_VGA) {
        vga_text_write(str, strlen(str));
    }
}

void shell_writeln(const char *str) {
    if (CURRENT_SHELL_MODE == SHELL_MODE_VGA) {
        vga_text_write(str, strlen(str));
        vga_reset_caret();
    }
}