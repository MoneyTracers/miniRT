/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/01 17:28:02 by maraasve      #+#    #+#                 */
/*   Updated: 2024/12/03 18:23:35 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "tuples.h"
# include "../lib/libft/inc/libft.h"
# include "color.h"
# include <stdbool.h>
# include <math.h>
# include <shapes.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <fcntl.h>

# define RED   "\x1B[31m"
# define GRN   "\x1B[1;32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define BMAG   "\x1B[1;35m"
# define CYN   "\x1B[36m"
# define BCYN   "\x1B[1;36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

# define SUCCESS 0
# define ERROR 1
# define EPSILON 0.001

# ifndef DEBUG
#  define DEBUG 0
# endif

# ifndef BONUS
#  define BONUS 0
# endif

typedef float				t_fvec \
__attribute__ ((vector_size (4 * sizeof(float))));

typedef struct s_mlx t_mlx;

typedef struct s_camera
{
	int			image_width;
	int			image_heigth;
	float		fov;
	float		half_width;
	float		half_height;
	float		aspect_ratio;
	float		pixel_size;
	t_tuple		pos;
	t_tuple		normal;
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	transformation;
	t_matrix	inverse;
}	t_camera;

typedef struct s_light
{
	t_tuple			pos;
	t_color			color;
	float			brightness;
	struct s_light	*next;
}	t_light;

typedef enum e_error
{
	DEFAULT,
	GNL,
	CLOSE,
	INC_FORMAT,
	A_IDENTIFIER,
	L_IDENTIFIER,
	C_IDENTIFIER,
	NORMAL,
	OBJECT,
	LIGHT
} e_error;

typedef struct s_world
{
	t_light			*lights;
	t_color			ambient;
	float			ambientf;
	t_camera		cam;
	t_object		*objects;
	t_mlx			*mlx_data;
	int				exit_code;
	int				err;
}	t_world;

void	debugger(char *format, ...);
void	exit_err(char *err, int ec);
void set_error(t_world *world, int exit_code, int err_msg, void *mem);

#endif
