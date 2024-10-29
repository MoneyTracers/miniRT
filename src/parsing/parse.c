/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/29 14:57:19 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/29 17:23:22 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <parse.h>

void	parse_check_extension(char *file)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(file);
	while (i < len)
	{
		if (file[i] == '.')
			break ;
		i++;
	}
	if (i == len)
		exit (1);
	if (ft_strncmp(&file[i], ".rt", 3))
		exit (1);
}

int	parse_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	return (fd);
}

int	parse_file_identify(char *str)
{
	int	type;

	if (ft_strlen(str) < 3)
		type = unidentified;
	else if (!ft_strncmp(str, "A ", 2))
		type = ambient;
	else if (!ft_strncmp(str, "C ", 2))
		type = camera;
	else if (!ft_strncmp(str, "L ", 2))
		type = light;
	else if (!ft_strncmp(str, "sp ", 2))
		type = sphere;
	else if (!ft_strncmp(str, "pl ", 2))
		type = plane;
	else if (!ft_strncmp(str, "cy ", 2))
		type = cyl;
	else 
		type = unidentified;
	return (type);
}

int	parse_file_line_count(char *str)
{
	int	fd;
	fd = parse_open_file(str);
	//TODO: loop with read and count amount of \n
	close (fd);
	return (0)
}

void	parse_file_lines(int line_count, char *file)
{
	int	i;
	int	fd;
	char *str;

	i = 0;
	fd = parse_open_file(str);
	while (i < line_count)
	{
		str = get_next_line(fd, 0);
		//TODO: identify type
		//TODO: check if capital identifier has already been
		//TODO: check correctness of line
		//TODO: add information to parsing struct
		i++;
	}
	get_next_line(0, 2);
}

void	parse_file(char *file)
{
	int		line_count;

	line_count = parse_file_line_count(file);
	parse_file_lines(line_count, file);
}

void	parse(int argc, char **argv)
{
	int	fd;

	if (argc < 2 || argc > 2)
		exit(1);
	parse_check_extension(argv[1]);
	fd = parse_open_file(argv[1]);
	parse_file(fd);
	if (close(fd) == -1)
		exit (1);
	exit(0);
}
