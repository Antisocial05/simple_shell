#include "shell.h"
#include <unistd.h>
/**
* anti_putchar - Prints a character using putchar
* @scoial_char: Character to be printed
* Return: Returns an integer whenever used
*/
int anti_putchar(char scoial_char)
{
	return (write(STDOUT_FILENO, &scoial_char, 1));
}
