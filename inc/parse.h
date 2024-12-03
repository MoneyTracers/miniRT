/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/01 17:28:02 by maraasve      #+#    #+#                 */
/*   Updated: 2024/12/03 22:19:18 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#ifndef PARSE_H
# define PARSE_H

# include <transformation.h>

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

typedef struct s_pobj
{
	int					i;
	int					type;
	float				diameter;
	float				height;
	t_tuple				coor;
	t_tuple				normal;
	t_material			m;
	t_transformation	transform;
} t_pobj;


t_tuple parse_get_normal(char *str, int *i);
int parse_check_unidentified(char *str);
int parse_check_cyl(char *str);
int parse_check_plane(char *str);
int parse_check_sphere(char *str);
int	parse_line_count(char *str);
void	parse_add_sphere(t_world *world, char *str);
void	parse_add_plane(t_world *world, char *str);
void	parse_add_cyl(t_world *world, char *str);
void	parse_add_ambient(t_world *world, char *str);
void	parse_add_camera(t_world *world, char *str);
void	parse_add_light(t_world *world, char *str);
t_tuple parse_get_coordinates(char *str, int *i);
float parse_get_float(char *str, int *i);
t_color parse_get_color(char *str, int *i);
int	parse_isint(char *num, int *i);
int	parse_isfloat(char *num, char end_delim, int *i);
int	parse_inrange_int(int min, int max, char *num, int* i);
int parse_isnormalvec(char *vec, int *i);
int parse_iscoordinates(char *coor, int *i);
int	atoin(const char *nptr, int len);
int parse_inrange_rgb(int min, int max, char *rgb, int* i);
float	atofn(const char *nptr, int len);
int	parse_skipwhitespace(char *str, int i);
int	parse_inrange_float(float min, float max, char *str, int *i);
void	parse_check_extension(char *file);
int	parse_check_correctness(t_parse *parse);
void	parse_check_identifier(t_world *world, t_parse *parse);
int	parse_check_identify(char *str);
int	parse_open_file(char *file);
void	parse_lines(t_world *world, int line_count, char *file);
void	parse(t_world *world, int argc, char **argv);
void	parse_add_obj(t_world *world, void *shape, t_matrix matrix, t_pobj parse);

#endif

