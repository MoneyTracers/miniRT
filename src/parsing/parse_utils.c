/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 13:57:38 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/13 12:12:28 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <minirt.h>

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
