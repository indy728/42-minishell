/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:44:43 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/01 18:41:22 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sys_prompt(void)
{
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	ft_printf("~%s $> ", cwd);
}

int		escape(char *str, int i)
{
	if (i > 0 && str[i - 1] == '\\')
		return (1);
	return (0);
}

char	is_open_quote(char *str, int pos)
{
	int		quote;
	char	type;
	int	i;

	i = -1;
	quote = 0;
	while (++i < pos && str[i])
	{
		if (!quote && (str[i] == '"' || str[i] == '\'') && !escape(str, i))
		{
			++quote;
			type = str[i];
		}
		else if (quote && str[i] == type && !escape(str, i))
			--quote;
	}
	if (quote)
		return (type);
	return (0);
}

char	is_escaped(char *str, int i)
{
	if ((i && str[i - 1] == '\\') || is_open_quote(str, i))
		return (1);
	return (0);
}

void	get_commands(char *line, char ***commands)
{
	int		i;
	int		count;
	char	**cmds;

	i = -1;
	count = 1;
	while (line[++i])
	{
		if (line[i] ==';' && i && line[i - 1] != '\\'
				&& !is_open_quote(line, i))
			++count;
	}
	if (!(cmds = ft_memalloc(sizeof(char *) * (count + 1))))
		exit (1);
	i = -1;
	count = 0;
	while (line[++i])
	{
		if (line[i] ==';' && i && line[i - 1] != '\\'
				&& !is_open_quote(line, i))
		{
			cmds[count++] = ft_strndup(line, i);
			line = line + i + 1;
			i = -1;
		}
	}
	cmds[count++] = ft_strdup(line);
	cmds[count] = NULL;
	*commands = cmds;
}

char	**commands(char *line, char **env)
{
	char	**commands;
	int		i;

	i = -1;
	commands = ms_strsplit(line, ';');
	ft_print_r(commands);
	while (commands[++i])
		env = ms_execute_command(commands[i], env);
	ft_del_r(commands);
	return (env);
}

int	main(int ac, char **av, char **environ)
{
	char *line;
	char	**env;
	//char	**args;

	(void)ac;
	(void)av;
	if (!(env = ft_dup_r(environ)))
		ft_exit_malloc_error("ft_dup_r", ft_size_r(environ));
	while (1)
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
/*		while (commands[++i])
			ms_execute_command(commands[i], environ);
		while (i >= 0)
			ft_strdel(&(commands[i--]));
*/	}
	return (0);
}
