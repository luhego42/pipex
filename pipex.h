#ifndef PIPEX_PIPEX_H
#define PIPEX_PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

char *get_path(char **env, char *cmd);
char *find_path(char *path_lst, char *cmd);
void    exec_cmd(char *argv, char **env);
#endif
