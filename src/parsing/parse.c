/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/29 14:57:19 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/05 17:14:56 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <parse.h>

void	parse_add_object(t_world *world, t_parse *parse)
{
	debugger(BLU "%s:%d - %s\nadd object:\t%sobject type:\t%d\n\n" RESET, __FILE__, __LINE__, __FUNCTION__ ,parse->str, parse->type);
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
		debugger(CYN "%s:%d - %s\nparse str:\t%s" RESET, __FILE__, __LINE__, __FUNCTION__ ,parse.str);
		if (parse.str == NULL)
		{
			perror("gln error\n");
			exit (1);
		}
		parse.type = parse_check_identify(parse.str);
		debugger(CYN "%s:%d - %s\nparse type:\t%d\n\n" RESET, __FILE__, __LINE__,__FUNCTION__ , parse.type);
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

	if (argc < 2 || argc > 2)
	{
		perror("wrong arguments");
		exit(1);
	}
	parse_check_extension(argv[1]);
	line_count = parse_line_count(argv[1]);
	debugger(BLU "%s:%d - %s\nline count:\t%d\n\n" RESET, __FILE__, __LINE__, __FUNCTION__, line_count);
	parse_lines(&world, line_count, argv[1]);
	exit(0);
}
