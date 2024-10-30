/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/29 14:57:19 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/30 14:33:49 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <parse.h>

void	parse_lines(int line_count, char *file)
{
	int	i;
	int	fd;
	int	type;
	char *str;
	t_parse parse;

	i = 0;
	ft_bzero(&parse, sizeof(t_parse));
	fd = parse_open_file(str);
	while (i < line_count)
	{
		str = get_next_line(fd, 0);
		type = parse_check_identify(str);
		parse_check_identifier(&parse, type);
		if (parse_check_correctness(str, type))
		{
			perror("incorrect format in file");
			exit (1);
		}
		//TODO: add information to parsing struct
		i++;
	}
	get_next_line(0, 2);
}

void	parse(int argc, char **argv)
{
	int	fd;
	int		line_count;

	if (argc < 2 || argc > 2)
	{
		perror("wrong arguments");
		exit(1);
	}
	parse_check_extension(argv[1]);
	line_count = parse_line_count(argv[1]);
	parse_lines(line_count, argv[1]);
	exit(0);
}
