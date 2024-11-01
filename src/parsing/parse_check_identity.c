/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_check_identity.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 14:02:22 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/31 16:59:32 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
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

void	parse_check_identifier(t_parse *parse, int type)
{
		if (type == ambient)
		{
			if (parse->A_identifier)
			{
				perror("too many A identifiers");
				exit (1);
			}
			parse->A_identifier++;
		}
		else if (type == camera)
		{
			if (parse->C_identifier)
			{
				perror("too many C identifiers");
				exit (1);
			}
			parse->C_identifier++;
		}
		//TODO: if bonus then multiple lights
		else if (type == light )
		{
			if (parse->L_identifier)
			{
				perror("too many L identifiers");
				exit (1);
			}
			parse->L_identifier++;
		}
}