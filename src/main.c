/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:44:43 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/03 14:16:38 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sys_prompt(char **env)
{
	char	cwd[CWD_BUF];
	char	*home;
	int		n;

	getcwd(cwd, sizeof(cwd));
	if (!(home = find_arg("HOME", env)) || !*home)
	{
		/*ms_builddir("HOME", cwd, env)*/;
		home = ft_strmove(find_arg("HOME", env), &home);///changed strmove, hope it works
	}
	if ((n = ft_strlnstr(cwd, home)) < 0)
		ft_printf(GREEN "%s $> " RESET, GREEN, cwd);
	else
		ft_printf(GREEN "~%s $> " RESET, cwd + n);
	ft_strdel(&home);
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
		ft_exit_malloc_error("ft_dup_r", (ft_size_r(environ) + 1) * 8);
	while (!g_exit)
	{
		sys_prompt(env);
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
