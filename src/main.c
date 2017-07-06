/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:17:07 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/06 00:30:08 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sys_prompt(char **prompt, char **env)
{
	char	cwd[CWD_BUF];
	char	*home;
	int		n;

	if (g_nl)
	{
		g_nl = 0;
		ft_printf(BWHITE""BLACK"%%"RESET"\n");
	}
	if (prompt)
		ft_printf("%s%s " RESET, prompt[1], prompt[0]);
	else
	{
		getcwd(cwd, sizeof(cwd));
		home = find_arg("HOME", env);
		if ((n = ft_strlnstr(cwd, home)) < 0)
			ft_printf(GREEN "%s $> " RESET, cwd);
		else
			ft_printf(GREEN "~%s $> " RESET, cwd + n);
		ft_strdel(&home);
	}
}

char	*get_color(char *color)
{
	if (!ft_strcmp(ft_tolowerstr(color), "black"))
		return (ft_strdup(BLACK));
	if (!ft_strcmp(ft_tolowerstr(color), "red"))
		return (ft_strdup(RED));
	if (!ft_strcmp(ft_tolowerstr(color), "white"))
		return (ft_strdup(WHITE));
	if (!ft_strcmp(ft_tolowerstr(color), "yellow"))
		return (ft_strdup(YELLOW));
	if (!ft_strcmp(ft_tolowerstr(color), "blue"))
		return (ft_strdup(BLUE));
	if (!ft_strcmp(ft_tolowerstr(color), "magenta"))
		return (ft_strdup(MAGENTA));
	if (!ft_strcmp(ft_tolowerstr(color), "cyan"))
		return (ft_strdup(CYAN));
	return (ft_strdup(GREEN));
}

char	**get_prompt(int ac, char **av)
{
	char	**prompt;

	g_exit = 0;
	g_nl = 0;
	ft_printf(CLEAR""BBLUE""BOLD""RED);
	ft_printfile("ascii_art/header.txt");
	ft_printf(RESET "\n");
	if (2 < ac && ac <= 4 && !ft_strcmp(av[1], "-p"))
	{
		prompt = ft_memalloc(sizeof(char *) * 3);
		prompt[0] = ft_strdup(av[2]);
		prompt[1] = (ac == 4) ? get_color(av[3]) : ft_strdup("");
		prompt[2] = NULL;
		return (prompt);
	}
	else if (ac > 1)
	{
		ft_printf(CLEAR"usage: minishell: " MS_USAGE "\n");
		g_exit = 1;
	}
	return (NULL);
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
	if (g_exit == 1)
		ft_printf(CLEAR);
	return (env);
}

int		main(int ac, char **av, char **environ)
{
	char	*line;
	char	**env;
	char	**prompt;

	prompt = get_prompt(ac, av);
	if (!(env = ft_dup_r(environ)))
		ft_exit_malloc_error("ft_dup_r", (ft_size_r(environ) + 1) * 8);
	while (!g_exit)
	{
		ft_strdel(&line);
		sys_prompt(prompt, env);
		if (get_next_line(0, &line) < 0)
		{
			ft_del_r(env);
			ft_del_r(prompt);
			ft_exit_read_error("get_next_line", &line, 0);
		}
		if (!*line)
			continue ;
		env = commands(line, env);
	}
	ft_strdel(&line);
	ft_del_r(env);
	ft_del_r(prompt);
	return (0);
}
