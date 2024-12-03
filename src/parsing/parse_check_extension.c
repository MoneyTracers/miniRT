/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_check_extension.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 14:02:53 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/29 12:36:10 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

void	parse_check_extension(char *file)
{
	char	*temp;

	temp = ft_strrchr(file, '.');
	if (temp == NULL)
		exit_err("no extension with file", 1);
	else if (ft_strlen(temp) != 3)
		exit_err("wrong extension format", 1);
	else if (ft_strncmp(temp, ".rt", 3))
		exit_err("wrong extension", 1);
}
