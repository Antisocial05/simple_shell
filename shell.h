#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
void anti_cmds(char **anti_cmds, size_t *anti_sizes);
void anti_env(char **anti_envs);
ssize_t anti_getline(char **anti_buff, size_t *anti_size);
void anti_prompt(void);
int anti_putchar(char anti_chara);
int anti_putchar(char anti_chara);
void anti_executor(const char *anti_cmd_line);
int anti_printf(const char *antistring);
#endif
