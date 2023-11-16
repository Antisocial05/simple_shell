#include "shell.h"
#include <string.h>

/**
 * anti_executor - exect being passed
 * @scoial_cmd_line: line cmd
 */
void anti_executor(const char *scoial_cmd_line);

void anti_executor(const char *scoial_cmd_line)
{
	char *scoial_args[128];
	int scoial_argument_count = 0;
	char *scoial_delim = "\n\t";
	char *scoial_myenv[] = {NULL};
	pid_t scoial_pid = fork();

	if (scoial_pid == -1)
	{
		perror("fork Error");
		exit(EXIT_FAILURE);
	}
	else if (scoial_pid == 0)
	{
		char *scoial_token = strtok((char *)scoial_cmd_line, scoial_delim);

		while (scoial_token != NULL)
		{
			scoial_args[scoial_argument_count++] = scoial_token;
			scoial_token = strtok(NULL, scoial_delim);
		}
		scoial_args[scoial_argument_count] = NULL;

		if (strcmp(scoial_args[0], "clear") == 0)
			if (system("clear") == -1)
			{
				perror("clear");
				exist(EXIT_FAILURE);
			}
		exit(EXIT_SUCCESS);
	}
	if (strchr(scoial_args[0], '/') != NULL)
	{
		if (execve(scoial_args[0], scoial_args, scoial_myenv) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		char *scoial_pathenvs = getenv("PATH");
		char *scoial_pathcpy = strdup(scoial_pathenvs);
		char *scoial_path = strtok(scoial_pathcpy, ":");

		free(scoial_pathcpy);
		while (scoial_path != NULL)
		{
			char scoial_fullpth[256];

			snprintf(scoial_fullpth, sizeof(scoial_fullpth),
			"%s/%s", scoial_path, scoial_args[0]);
			if (execve(scoial_fullpth, scoial_args, scoial_myenv) != -1)
			{
				exit(EXIT_SUCCESS);
			}
			scoial_path = strtok(NULL, ":");
		}

		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
