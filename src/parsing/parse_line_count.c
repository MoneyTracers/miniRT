/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:57:19 by spenning          #+#    #+#             */
/*   Updated: 2024/12/16 15:56:09 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <parse.h>

// TODO: check line count
int	parse_line_count_loop(int fd, int *line_count)
{
	ssize_t	ret;
	char	buf[100];
	int		i;

	ret = 0;
	i = 0;
	ret = read(fd, buf, 99);
	debugger(GRN"%s:%d - %s\nread return:\t%d\n\n"RESET, \
	__FILE__, __LINE__, __FUNCTION__, ret);
	if (ret == -1)
		exit_err("read error in parse_file_line_count", 1);
	else if (ret == 0)
		return (0);
	i = 0;
	while (i < ret)
	{
		if (buf[i] == '\n')
			*line_count += 1;
		i++;
	}
	if (ret < 99 && buf[ret - 1] != '\n')
		*line_count += 1;
	return (1);
}

int	parse_line_count(char *str)
{
	int		fd;
	int		line_count;

	line_count = 0;
	fd = parse_open_file(str);
	while (parse_line_count_loop(fd, &line_count))
	{
	}
	if (close (fd))
		exit_err("close error in parse_file_line_count", 1);
	return (line_count);
}
