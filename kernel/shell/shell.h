#ifndef _SHELL_H_
#define _SHELL_H_
#include <stddef.h>
#include <stdint.h>

enum shell_mode {
    SHELL_MODE_NONE = 0,
    SHELL_MODE_VGA = 1,
    /* to be more? */
};

enum shell_text_color {
	SHELL_TEXT_COLOR_BLACK = 0,
	SHELL_TEXT_COLOR_BLUE = 1,
	SHELL_TEXT_COLOR_GREEN = 2,
	SHELL_TEXT_COLOR_CYAN = 3,
	SHELL_TEXT_COLOR_RED = 4,
	SHELL_TEXT_COLOR_MAGENTA = 5,
	SHELL_TEXT_COLOR_BROWN = 6,
	SHELL_TEXT_COLOR_LIGHT_GREY = 7,
	SHELL_TEXT_COLOR_DARK_GREY = 8,
	SHELL_TEXT_COLOR_LIGHT_BLUE = 9,
	SHELL_TEXT_COLOR_LIGHT_GREEN = 10,
	SHELL_TEXT_COLOR_LIGHT_CYAN = 11,
	SHELL_TEXT_COLOR_LIGHT_RED = 12,
	SHELL_TEXT_COLOR_LIGHT_MAGENTA = 13,
	SHELL_TEXT_COLOR_LIGHT_BROWN = 14,
	SHELL_TEXT_COLOR_WHITE = 15,
};

void shell_init(enum shell_mode mode);
void shell_set_text_color(enum shell_text_color color);
void shell_write(const char *str);
void shell_writeln(const char *str);
#endif