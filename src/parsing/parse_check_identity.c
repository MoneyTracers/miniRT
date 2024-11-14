/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_check_identity.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 14:02:22 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/13 13:44:17 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

int	parse_check_identify(char *str)
{
	int	type;

	if (ft_strlen(str) < 3)
		type = unidentified;
	else if (!ft_strncmp(str, "A ", 2))
		type = ambient;
	else if (!ft_strncmp(str, "C ", 2))
		type = camera;
	else if (!ft_strncmp(str, "L ", 2))
		type = light;
	else if (!ft_strncmp(str, "sp ", 2))
		type = sphere;
	else if (!ft_strncmp(str, "pl ", 2))
		type = plane;
	else if (!ft_strncmp(str, "cy ", 2))
		type = cyl;
	else
		type = unidentified;
	return (type);
}

//TODO: count amount of objects for array later
void	parse_check_identifier(t_parse *parse)
{
	debugger(CYN "%s:%d - %s\nparse str:\t%s" RESET, __FILE__, \
	__LINE__, __FUNCTION__, parse->str);
	debugger(CYN "%s:%d - %s\nparse type:\t%d\n\n" RESET, __FILE__, \
	__LINE__, __FUNCTION__, parse->type);
	debugger(GRN "%s:%d - %s\ncheck (A, L, C)\n\n" RESET, __FILE__, \
	__LINE__, __FUNCTION__);
	if (parse->type == ambient)
	{
		if (parse->A_identifier)
			exit_err("too many A identifiers", 1);
		parse->A_identifier++;
	}
	else if (parse->type == camera)
	{
		if (parse->C_identifier)
			exit_err("too many C identifiers", 1);
		parse->C_identifier++;
	}
	else if (parse->type == light)
	{
		if (parse->L_identifier && !BONUS)
			exit_err("too many L identifiers", 1);
		parse->L_identifier++;
	}
}
