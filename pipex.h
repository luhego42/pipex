/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:30:09 by luhego            #+#    #+#             */
/*   Updated: 2023/10/26 15:30:13 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*get_path(char **env, char *cmd);
char	*find_path(char *path_lst, char *cmd);
void	exec_cmd(char *argv, char **env);
#endif
