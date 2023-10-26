/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:26:31 by luhego            #+#    #+#             */
/*   Updated: 2023/10/26 15:59:28 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *path_lst, char *cmd)
{
	int		path_size;
	int		cmd_size;
	char	*origin_path;

	path_size = ft_strlen(path_lst) + 1;
	cmd_size = ft_strlen(cmd) + 1;
	origin_path = malloc(sizeof(char) * (path_size + cmd_size));
	origin_path[0] = 0;
	ft_strlcat(origin_path, path_lst, path_size);
	origin_path[path_size - 1] = '/';
	origin_path[path_size] = '\0';
	ft_strlcat(origin_path, cmd, path_size + cmd_size);
	return (origin_path);
}

char	*get_path(char **env, char *cmd)
{
	char	**path_lst;
	char	*path;
	int		i;

	i = 0;
	while (ft_strncmp("PATH=", env[i], 5) != 0)
		i++;
	path_lst = ft_split(&env[i][5], ':');
	i = 0;
	while (path_lst[i])
	{
		path = find_path(path_lst[i], cmd);
		if (access(path, X_OK) == 0)
			return (path);
		else
			free(path);
		i++;
	}
	return (NULL);
}

void	exec_cmd(char *argv, char **env)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (access(cmd[0], X_OK) == -1)
		cmd[0] = get_path(env, cmd[0]);
	execve(cmd[0], &cmd[0], env);
	ft_free_double_tab(cmd);
}
