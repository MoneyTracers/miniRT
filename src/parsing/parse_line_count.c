/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_line_count.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/29 14:57:19 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/30 14:11:44 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <parse.h>

int	parse_line_count(char *str)
{
	int		fd;
	ssize_t	ret;
	char	buf[100];
	int		i;
	int		line_count;

	line_count = 0;
	fd = parse_open_file(str);
	ret = 0;
	while (1)
	{
		ret = read(fd, buf, 99);
		if (ret == -1)
		{
			perror("read error in parse_file_line_count");
			exit (1);
		}
		else if (ret == 0)
			break;
		buf[99] = '0';
		i = 0;
		while (buf[i] < 100)
		{
			if (buf[i] == '\n')
				line_count++;
		}
	}
	if (close (fd))
	{
		perror("close error in parse_file_line_count");
		exit (1);
	}
	return (line_count)
}
