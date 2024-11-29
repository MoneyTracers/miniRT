/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:06:00 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/29 15:26:20 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <shapes.h>
#include <transformation.h>
#include <intersection.h>
#include <mini_mlx.h>
#include <libft.h>
#include <lighting.h>
#include <free.h>
#include <shapes.h>
#include <list.h>
#include <mlx.h>
#include <camera.h>
#include <parse.h>

int	main(int argc, char **argv)
{
	t_mlx				mlx_data;
	t_world				world;

	ft_bzero(&world, sizeof(t_world));
	ft_bzero(&mlx_data, sizeof(t_mlx));
	parse(&world, argc, argv);
	
	if (!init_mlx(&mlx_data))
	{
		free_objects(&world.objects);
		return (1);
	}

	mlx_data.world = &world; // added world to data struct for the keyhooks, for now

	hooks(&mlx_data);
	render(&mlx_data, world.cam, &world);
	printf("DONE\n");
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.window, mlx_data.img1.image, 0, 0);
	mlx_loop(mlx_data.mlx);
	
	free_mlx(&mlx_data);
	free_lights(&world.lights);
	free_objects(&world.objects);
}
