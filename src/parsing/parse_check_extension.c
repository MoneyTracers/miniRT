/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_check_extension.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 14:02:53 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/14 15:39:15 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

void	parse_check_extension(char *file)
{
	char	*temp;

	temp = ft_strrchr(file, '.');
	if (temp == NULL)
	{
		perror("no extension with file");
		exit (1);
	}
	if (ft_strlen(temp) != 3)
	{
		perror("wrong extension format");
		exit (1);
	}
	if (ft_strncmp(temp, ".rt", 3))
	{
		perror("wrong extension");
		exit (1);
	}
}
