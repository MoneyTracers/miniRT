/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 19:13:18 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:55:20 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	endl;

	endl = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &endl, 1);
}
