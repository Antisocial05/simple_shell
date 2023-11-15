#include "shell.h"

/**
* anti_cmds - Entry point for the main command
* @scoial_cmds: Command input parsed into the function
* @scoial_size: Size of the  parsed command within the function
*/
void anti_cmds(char **scoial_cmds, size_t *scoial_size)
{
	ssize_t scoial_read;

	scoial_read = anti_getline(scoial_cmds, scoial_size);

	if (scoial_read == -1)
	{
		if (*scoial_cmds == NULL)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		if (feof(stdin))
		{
			anti_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	if ((*scoial_cmds)[scoial_read - 1] == '\n')
	{
		(*scoial_cmds)[scoial_read - 1] = '\0';
		*scoial_size = strlen(*scoial_cmds);
	}
}
