/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atofn.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 19:06:39 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/12 16:21:41 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

  
#include <parse.h>

static char	*skipwhitespaces(char *c_ptr)
{
	while ((*c_ptr > 8 && *c_ptr < 14) || *c_ptr == 32)
	{
		c_ptr++;
	}
	return (c_ptr);
}

static int	detect_plusmignus(char *c_ptr)
{
	size_t	plus_flag;
	size_t	minus_flag;	

	plus_flag = 0;
	minus_flag = 0;
	if (*c_ptr == '+')
		plus_flag = plus_flag + 1;
	if (*c_ptr == '-')
		minus_flag = minus_flag + 1;
	if (minus_flag == 1 && (ft_isdigit(c_ptr[1]) == 1))
		return (1);
	if (plus_flag == 1 && (ft_isdigit(c_ptr[1]) == 1))
		return (2);
	if (minus_flag == 0 && plus_flag == 0 && (ft_isdigit(*c_ptr) == 1))
		return (3);
	if (minus_flag == 0 && plus_flag == 0 && c_ptr[0] == 0)
		return (3);
	return (4);
}

float decimals(float result, const char *str, int i, int len)
{
	int	nexponent;
	int temp;
	int chr;

	nexponent = 1;
	if (str[i] != '.')
		return (result);
	i++;
	while (i < len)
	{
		chr = (str[i] - 48);
		temp = 10 * nexponent;
		result += (float)chr / temp;
		i++;
		nexponent++;
	}
	return (result);
}

float	atofn(const char *nptr, int len)
{
	float		result;
	int		index;
	int		flag;
	char	*c_ptr;

	c_ptr = (char *)nptr;
	result = 0;
	index = 0;
	c_ptr = skipwhitespaces(c_ptr);
	flag = detect_plusmignus(c_ptr);
	if (flag == 1 || flag == 2)
		c_ptr++;
	while (c_ptr[index] != '.' && c_ptr[index] != ' ' \
	&& c_ptr[index] != '\0' \
	&& (c_ptr[index] > 47) && (c_ptr[index] < 58))
	{
		result = result * 10 + (c_ptr[index] - 48);
		index++;
	}
	result = decimals(result, &c_ptr[index], index - 1, len - index);
	if (flag == 1)
		return (result * -1);
	if (flag == 2 || flag == 3)
		return (result);
	return (0);
}

