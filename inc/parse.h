/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/01 17:28:02 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/01 15:12:39 by spenning      ########   odam.nl         */
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
	char	*str;
	int		type;
	int		A_identifier;
	int		C_identifier;
	int		L_identifier;
} t_parse;

float parse_get_float(char *str, int *i);
t_color parse_get_color(char *str, int *i);
int	parse_isint(char *num, char end_delim, int *i);
int	parse_isfloat(char *num, char end_delim, int *i);
int	parse_isinrange_int(int min, int max, char *num, int* i);
int parse_isnormalvec(char *vec, int *i);
int parse_iscoordinates(char *coor, int *i);
int	atoin(const char *nptr, int len);
int parse_isrgb_inrange(int min, int max, char *rgb, int* i);
double	atofn(const char *nptr, int len);
int	parse_skipwhitespace(char *str, int i);
int	parse_inrange_float(double min, double max, char *str, int *i);
void	parse_check_extension(char *file);
int	parse_check_correctness(char *str, int type);
void	parse_check_identifier(t_parse *parse);
int	parse_check_identify(char *str);
int	parse_open_file(char *file);
void	parse_lines(t_world world, int line_count, char *file);
void	parse(t_world world, int argc, char **argv);

#endif

