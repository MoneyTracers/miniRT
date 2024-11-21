/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/01 17:28:02 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/21 19:53:07 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//https://dev.to/pauljlucas/proper-header-file-etiquette-ola

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

typedef struct s_bvh t_bvh;
typedef struct s_aabb t_aabb;

typedef struct s_ab
{
	t_fvec bmin;
	t_fvec bmax;
} t_ab;


typedef struct s_camera
{
	int		image_width;
	int		image_heigth;
	float	fov;
	float	half_width;
	float	half_height;
	float	aspect_ratio;
	float	pixel_size;
	t_matrix	tranformation;
	t_matrix	*inverse;

	// int		samples_per_pixel;
	// int		max_depth;
	// double	pixel_samples_scale;
	// double	focal_length;
	// double	viewport_heigth;
	// double	viewport_width;
	// t_tuple	lookfrom;
	// t_tuple	lookat;
	// t_tuple	vup;
	// t_tuple	viewport_u;
	// t_tuple	viewport_v;
	// t_tuple	center;
	// t_tuple	pixel_delta_u;
	// t_tuple	pixel_delta_v;
	// t_tuple	viewport_upper_left;
	// t_tuple	pixel00_loc;
}	t_camera;

typedef	struct s_light
{
	t_tuple			pos;
	t_color			color;
	float			brightness;
	struct s_light	*next;
}	t_light;


typedef	struct s_tri
{
	t_fvec vertex0;
	t_fvec vertex1;
	t_fvec vertex2;
	t_fvec centroid;
} t_tri;

typedef struct s_bvh
{
	t_fvec			aabb_min;
	t_fvec			aabb_max;
	unsigned int	left_first;
	unsigned int	tri_Count;
	t_bvh		*left;
	t_bvh		*right;
	t_aabb		bbox;
	t_object	*object;
}	t_bvh;

typedef struct s_world
{
	t_light			*lights;
	t_color			ambient;
	float			ambientf;
	t_camera		cam;
	t_object		*objects;
	int				obj_count;
	int				arr_size;
	t_object		**objects_arr;
	t_bvh			**bvh;
	t_tri			*tri;
	unsigned int	*tri_index;
	int				node_used;
}	t_world;

void	debugger(char *format, ...);
void	exit_err(char *err, int ec);

#endif
