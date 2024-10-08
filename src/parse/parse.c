/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/12 14:51:29 by spenning      #+#    #+#                 */
/*   Updated: 2024/09/30 16:20:42 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int	check_path(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (ft_strncmp(path + (len - 3), "fdf", 3))
		return (1);
	return (0);
}

void	parse(char **argv, t_data *img)
{
	char	*path;
	int		fd;

	path = argv[1];
	if (check_path(path))
		exit(EXIT_FAILURE);
	img->map_path = path;
	img->columns = parse_colom(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		get_next_line(0, 2);
		perror("Failure with opening file descriptor during parsing");
		exit(EXIT_FAILURE);
	}
	img->rows = parse_rows(img->columns, fd);
	ft_debug("columns: %d rows: %d\n", img->columns, img->rows);
	if (img->columns <= 0 || img->rows <= 0)
	{
		get_next_line(0, 2);
		perror("Input incorrect, provide .fdf file with correct formating");
		exit(EXIT_FAILURE);
	}
}
