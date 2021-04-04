#include "shell/shell.h"
 
void kernel_main(void) 
{
	shell_init(SHELL_MODE_VGA);
	shell_set_text_color(SHELL_TEXT_COLOR_LIGHT_RED);
	shell_writeln("Hello, PeaceOS kernel World!");
	shell_writeln("");
	shell_writeln("This is some sort of welcome message.");
	shell_writeln("");
	shell_set_text_color(SHELL_TEXT_COLOR_LIGHT_BLUE);
	shell_writeln("Doing nothing now...");
}