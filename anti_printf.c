#include "shell.h"
/**
* anti_printf - Prints string to stdout
* @scoialstring: Output stdout string to be used
* Return: An integer whenever it is used
*/
int anti_printf(const char *scoialstring)
{
	return (write(STDOUT_FILENO, scoialstring, strlen(scoialstring)));
}
