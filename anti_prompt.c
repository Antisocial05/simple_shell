#include "shell.h"
/**
* anti_prompt - prompts for a command
*
*/
void anti_prompt(void)
{
	char scoial_wdir[1024];

	if (getcwd(scoial_wdir, sizeof(scoial_wdir)) == NULL)
	{
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
	anti_printf(scoial_wdir);
	anti_printf("$ ");
}
