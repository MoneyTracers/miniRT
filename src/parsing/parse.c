/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/29 14:57:19 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/01 14:34:22 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <parse.h>
#include <tuples.h>

void	parse_add_object(t_world *world, t_parse *parse)
{
	if (parse->type == ambient)
		parse_add_ambient(world, parse->str);
	else if (parse->type == camera)
		parse_add_camera(world, parse->str);
	else if (parse->type == light)
		parse_add_light(world, parse->str);
	else if (parse->type == sphere)
		parse_add_sphere(world, parse->str);
	else if (parse->type == plane)
		parse_add_plane(world, parse->str);
	else if (parse->type == cyl)
		parse_add_cyl(world, parse->str);
	free(parse->str);
	parse->str = NULL;
}


void	parse_lines(t_world *world, int line_count, char *file)
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
		parse.str = get_next_line(fd, 0);
		if (parse.str == NULL)
		{
			perror("gln error\n");
			exit (1);
		}
		parse.type = parse_check_identify(parse.str);
		parse_check_identifier(&parse);
		if (parse_check_correctness(str, type))
		{
			perror("incorrect format in file");
			exit (1);
		}
		parse_add_object(world, &parse);
		i++;
	}
	get_next_line(0, 2);
}

void	parse(t_world world, int argc, char **argv)
{
	int	fd;
	int		line_count;

	debugger(BLU "entering parsing\n" RESET);
	if (argc < 2 || argc > 2)
	{
		perror("wrong arguments");
		exit(1);
	}
	debugger(BLU "parse_extension_check\n" RESET);
	parse_check_extension(argv[1]);
	debugger(BLU "parse_line_count\n" RESET);
	line_count = parse_line_count(argv[1]);
	debugger(BLU "parse_lines\n" RESET);
	parse_lines(world, line_count, argv[1]);
	exit(0);
}
