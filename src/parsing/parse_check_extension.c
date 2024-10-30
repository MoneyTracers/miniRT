/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_check_extension.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 14:02:53 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/30 14:32:07 by spenning      ########   odam.nl         */
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
	{
		perror("no extension with file");
		exit (1);
	}
	if (ft_strncmp(&file[i], ".rt", 3))
	{
		perror("wrong extension");
		exit (1);
	}
}
