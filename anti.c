#include "shell.h"

/**
* main - Entgry point for the program
* @argc: Number of arguments passed to the program
* @argv: Array of arguments variables in the main function
* @env: Enviroment variables in the kernel
* Return: 0 for success, 1 for failure
*/
int main(int argc, char *argv[], char **env)
{
	char *scoial_cmd;
	size_t scoial_size;
	int scoial_exitstatus;
	size_t scoial_newlinepos;
	(void)argv;
	(void)argc;

	scoial_cmd = NULL;
	scoial_exitstatus = 0;

	while (1)
	{
		if (isatty(0) == 1)
			anti_prompt();
		anti_cmds(&scoial_cmd, &scoial_size);

		if (strcmp(scoial_cmd, "exit") == 0)
		{
			break;
		}
		else if (strncmp(scoial_cmd, "exit", 5) == 0)
		{
			scoial_exitstatus = atoi(scoial_cmd + 5);
			break;
		}
		else if (strcmp(scoial_cmd, "env") == 0 ||
		strcmp(scoial_cmd, "printenv") == 0)
			anti_env(env);
		anti_executor(scoial_cmd);

		scoial_newlinepos = strcspn(scoial_cmd, "\n");

		if (scoial_newlinepos < scoial_size)
			scoial_cmd[scoial_newlinepos] = '\0';

		if (scoial_cmd != NULL)
			scoial_cmd = NULL;
	}
	return (scoial_exitstatus);
}
