/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 13:57:38 by spenning      #+#    #+#                 */
/*   Updated: 2024/12/04 11:30:53 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <minirt.h>

t_transformation	get_transform_plane(t_tuple coor)
{
	t_transformation	transform;

	transform.rotate = create_identity_matrix();
	transform.scale = create_identity_matrix();
	transform.translation = translation_matrix(coor.x, coor.y, coor.z);
	return (transform);
}

t_transformation	get_transform_cyl(t_tuple coor, t_tuple normal, float dia)
{
	t_transformation	transform;

	transform.rotate = rotation_matrix_from_normal(normal);
	transform.scale = scale_matrix(dia, dia, dia);
	transform.translation = translation_matrix(coor.x, coor.y, coor.z);
	return (transform);
}

int	parse_skipwhitespace(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

int	parse_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	debugger(MAG "%s:%d - %s\nopening file:\t%s\nfile fd:\t%d\n\n" RESET, \
	__FILE__, __LINE__, __FUNCTION__, file, fd);
	if (fd == -1)
	{
		perror("unable to open file");
		exit(1);
	}
	return (fd);
}
