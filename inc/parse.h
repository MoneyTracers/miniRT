/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/01 17:28:02 by maraasve      #+#    #+#                 */
/*   Updated: 2024/10/30 14:23:46 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

enum identifiers
{
	ambient,
	camera,
	light,
	sphere,
	plane,
	cyl,
	unidentified
};

typedef struct s_parse
{
	int	A_identifier;
	int	C_identifier;
	int	L_identifier;
} t_parse;

void	parse_check_extension(char *file);
int	parse_check_correctness(char *str, int type);
void	parse_check_identifier(t_parse *parse, int type);
int	parse_check_identify(char *str);
int	parse_open_file(char *file);
int	parse_line_count(char *str);
void parse(int argc, char **argv);

#endif

