#include "shell.h"

/**
* anti_getline - Main program for reading input
* @scoial_buf: Buffer for storage
* @scoial_size: Size of the read buffer
* Return: A signed integer whenever called
*/
ssize_t anti_getline(char **scoial_buf, size_t *scoial_size)
{
	static char scoial_staticbuff[1024];

	ssize_t scoial_numread;

	*scoial_buf = NULL;

	if (*scoial_buf == NULL)
	{
		*scoial_buf = scoial_staticbuff;
	}
	*scoial_size = sizeof(scoial_staticbuff);

	scoial_numread = read(0, *scoial_buf, *scoial_size);

	if (scoial_numread == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (scoial_numread == 0)
	{
		if (isatty(0))
			anti_printf("\n");
		exit(EXIT_SUCCESS);
	}

	return (scoial_numread);
}
