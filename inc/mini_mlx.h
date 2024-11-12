/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:44:16 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/12 16:53:21 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_MLX_H
# define MINI_MLX_H

# include <color.h>

# define WINDOW_NAME "MiniRT"
# define HEIGHT 800
# define WIDTH 800

typedef struct s_mlx
{
	int		screen_width;
	int		screen_height;
	char	*addr;
	int		line_length;
	int		bpp;
	int		endian;
	void	*mlx;
	void	*window;
	void	*image;
}t_mlx;

int		init_mlx(t_mlx *data);
void	hooks(t_mlx *data);
void	pixel_put(t_mlx *data, int x, int y, t_color color);

#endif