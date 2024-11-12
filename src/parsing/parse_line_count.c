/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_line_count.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/29 14:57:19 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/08 11:51:45 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

  
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
		debugger(GRN"%s:%d - %s\nread return:\t%d\n\n"RESET, __FILE__, __LINE__, __FUNCTION__ , ret);
		if (ret == -1)
		{
			perror("read error in parse_file_line_count");
			exit (1);
		}
		else if (ret == 0)
			break;
		i = 0;
		while (i < ret)
		{
			if (buf[i] == '\n')
				line_count++;
			i++;
		}
	}
	if (close (fd))
	{
		perror("close error in parse_file_line_count");
		exit (1);
	}
	return (line_count);
}
