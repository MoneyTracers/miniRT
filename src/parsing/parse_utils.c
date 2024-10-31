/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 13:57:38 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/31 18:29:40 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <parse.h>

int	parse_isfloat(char *num, char end_delim)
{
	int	i;

	i = 0;
	if (!ft_isdigit(num[i]))
		return (0);
	while (ft_isdigit(num[i]))
		i++;
	if (num[i] != '.')
		return (0);
	i++;
	if (!ft_isdigit(num[i]))
		return (0);
	while (ft_isdigit(num[i]))
		i++;
	if (num[i] != end_delim)
		return (0);
	return (1);
}

int	parse_floatlen(char *num)
{
	int	i;

	i = 0;
	if (!ft_isdigit(num[i]))
		return (0);
	while (ft_isdigit(num[i]))
		i++;
	if (num[i] != '.')
		return (0);
	i++;
	if (!ft_isdigit(num[i]))
		return (0);
	while (ft_isdigit(num[i]))
		i++;
	if (num[i] != ' ')
		return (0);
	return (i);
}

int	parse_skipwhitespace(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

// check if number is in range of min and max with float
int	parse_inrange_float(double min, double max, char *str, int *i)
{
	double	num;
	int		index;
	int		len;

	if (!parse_isfloat(str[*i], ' '))
		return (0);
	len = parse_floatlen(str[*i]);
	num = ft_atofn(str[*i], len);
	*i += len;
	if (num < min || num > max)
		return (1);
	return (0);
}

// check if number is float like 0.2
int	parse_isinrange_int(int min, int max, char *num)
{
	
}

int	parse_check_number(char *str, char delim)
{
	int i;

	i = 0;
	while (str[i])
	{

	}
}

int parse_isrgb_inrange(int min, int max, char *rgb, int* i)
{
	int	len;

	len = 0;
	while (rgb[len] != ',')
		len++;
	
	
	//TODO:check R
	//TODO:if (good) iterate i to .
	//TODO:if (.) skip over .
	//TODO:check G
	//TODO:if (good) iterate i to .
	//TODO:if (.) skip over .
	//TODO:check B
	//TODO:if (good) iterate i to ' '
	//TODO:return (1)
}

int parse_iscoordinates(char *coor)
{
	
}

int parse_iscoordinates(char *coor)
{
	
}
int parse_isnormalvec(char *vec)
{
	
}

int	parse_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("unable to open file");
		exit(1);
	}
	return (fd);
}
