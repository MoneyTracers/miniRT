/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/30 17:06:00 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/14 16:44:16 by mynodeus      ########   odam.nl         */
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
	parse(&world, argc, argv);
	debugger(BLU "amount of objects parsed: %d\n" RESET, world.obj_count);
	print_matrix(world.cam.tranformation.grid, 4);
	printf("\n");
	print_matrix(world.cam.inverse->grid, 4);
	
	if (!init_mlx(&mlx_data))
	{
		free_objects(&world.objects);
		return (1);
	}
	
	hooks(&mlx_data);
	debugger(BLU "\nstart render\n"RESET);
	exit (0);
	render(&mlx_data, world.cam, &world);
	debugger(GRN"DONE\n"RESET);
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.window, mlx_data.image, 0, 0);
	mlx_loop(mlx_data.mlx);
	free_mlx(&mlx_data);
	free_lights(&world.lights);
	free_objects(&world.objects);
	free_matrix(world.cam.tranformation.grid, 4);
	free_matrix(world.cam.inverse->grid, 4);
}