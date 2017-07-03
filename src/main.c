/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:44:43 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/02 21:34:39 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sys_prompt(void)
{
	char cwd[CWD_BUF];
	getcwd(cwd, sizeof(cwd));
	ft_printf("~%s $> ", cwd);
}

char	**commands(char *line, char **env)
{
	char	**commands;
	int		i;

	i = -1;
	commands = ms_strsplit(line, ';');
	while (commands[++i] && !g_exit)
		env = ms_execute_command(commands[i], env);
	ft_del_r(commands);
	return (env);
}

int	main(int ac, char **av, char **environ)
{
	char	*line;
	char	**env;

	(void)ac;
	(void)av;
	g_exit = 0;
	if (!(env = ft_dup_r(environ)))
		ft_exit_malloc_error("ft_dup_r", ft_size_r(environ));
	while (!g_exit)
	{
		sys_prompt();
		if (get_next_line(0, &line) < 0)
		{
			ft_del_r(env);
			exit (1); ////// read error
		}
		if (!*line)
			continue ;
		env = commands(line, env);
	}
	ft_strdel(&line);
	ft_del_r(env);
	return (0);
}
