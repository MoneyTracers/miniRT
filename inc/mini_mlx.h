/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:44:16 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/15 17:04:57 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_MLX_H
# define MINI_MLX_H

# include <color.h>
# include <minirt.h>

# define WINDOW_NAME "MiniRT"
# define HEIGHT 800
# define WIDTH 800
# define ESC_KEY 65307
# define UP_KEY 65362
# define LEFT_KEY 65361
# define DOWN_KEY 65364
# define RIGHT_KEY 65363
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ZOOM_OUT 45
# define ZOOM_IN 61

typedef struct	s_img
{
	void	*image;
	char	*addr;
	int		line_length;
	int		bpp;
	int		endian;
} t_img;

typedef struct s_mlx
{
	t_world	*world;
	int		screen_width;
	int		screen_height;
	void	*mlx;
	void	*window;
	t_img	img1;
	t_img	img2;
	int		img_count;
}	t_mlx;

int		init_mlx(t_mlx *data);
void	hooks(t_mlx *data);
void	pixel_put(t_img *img, int x, int y, t_color color);

#endif