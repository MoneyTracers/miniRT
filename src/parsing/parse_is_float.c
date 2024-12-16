/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_is_float.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 15:14:54 by spenning      #+#    #+#                 */
/*   Updated: 2024/12/16 14:36:49 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <minirt.h>

int	parse_isfloatoverflow(int start, int end)
{
	if ((end - start) > 9)
		return (1);
	return (0);
}

int	parse_isfloat_integer(char *num, char end_delim, int *i)
{
	int	start;

	start = *i;
	if (num[*i] == '-')
		*i += 1;
	if (!ft_isdigit(num[*i]))
		return (-1);
	while (ft_isdigit(num[*i]))
		*i += 1;
	if (parse_isfloatoverflow(start, *i))
		return (-1);
	if (end_delim && num[*i] == end_delim)
		return (1);
	else if (num[*i] == ' ' || num[*i] == '\n')
		return (1);
	if (num[*i] != '.')
		return (-1);
	*i += 1;
	return (0);
}

int	parse_isfloat_decimal(char *num, char end_delim, int *i)
{
	int	start;

	start = *i;
	if (!ft_isdigit(num[*i]))
		return (-1);
	while (ft_isdigit(num[*i]))
		*i += 1;
	if (parse_isfloatoverflow(start, *i))
		return (-1);
	if (end_delim && num[*i] == end_delim)
		return (1);
	else if (num[*i] == ' ' || num[*i] == '\n')
		return (1);
	return (0);
}

int	parse_isfloat(char *num, char end_delim, int *i)
{
	int	ret;

	ret = parse_isfloat_integer(num, end_delim, i);
	if (ret == -1)
		return (0);
	else if (ret == 1)
		return (1);
	ret = parse_isfloat_decimal(num, end_delim, i);
	if (ret == -1)
		return (0);
	else if (ret == 1)
		return (1);
	return (1);
}
