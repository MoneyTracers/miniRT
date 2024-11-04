/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/29 14:57:19 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/04 18:23:07 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <parse.h>

void	parse_add_object(t_world *world, t_parse *parse)
{
	ft_debug(BLU "add object:\t%s\nobject type:\t%d\n" RESET, parse->str, parse->type);
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
	t_parse parse;

	i = 0;
	type = 0;
	ft_bzero(&parse, sizeof(t_parse));
	fd = parse_open_file(file);
	while (i < line_count)
	{
		parse.str = get_next_line(fd, 0);
		ft_debug(BLU "parse str:\t%s\n" RESET, parse.str);
		if (parse.str == NULL)
		{
			perror("gln error\n");
			exit (1);
		}
		parse.type = parse_check_identify(parse.str);
		ft_debug(BLU "parse type:\t%d\n" RESET, parse.type);
		ft_debug(BLU "check identifier (A, L, C)\n" RESET);
		parse_check_identifier(&parse);
		if (parse_check_correctness(&parse))
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
	int		line_count;

	ft_debug(BLU "entering parsing\n" RESET);
	if (argc < 2 || argc > 2)
	{
		perror("wrong arguments");
		exit(1);
	}
	ft_debug(BLU "parse_extension_check\n" RESET);
	parse_check_extension(argv[1]);
	ft_debug(BLU "parse_line_count\n" RESET);
	line_count = parse_line_count(argv[1]);
	ft_debug(BLU "line count:\t%d\n" RESET, line_count);
	ft_debug(BLU "parse_lines\n" RESET);
	parse_lines(&world, line_count, argv[1]);
	exit(0);
}
