#include "shell.h"
/**
* print_env - Prints enviroment variable to stdout
* @scoial_env: Enviroment variable to be printed
*/
void anti_env(char **scoial_env)
{
	int clay;

	for (clay = 0; scoial_env[clay] != NULL; clay++)
	{
		anti_printf(scoial_env[clay]);
		anti_putchar('\n');
	}
}
