/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/30 17:06:00 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/26 17:27:12 by spenning      ########   odam.nl         */
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


void parsing_exit(t_world * world)
{
	if (world->err == GNL)
		perror("gnl error");
	if (world->err == INC_FORMAT)
		perror("incorrect format in file");
	free_objects(&world->objects);
	free_lights(&world->lights);
	if (world->exit_code)
		exit(world->exit_code);
	return ;
}

int	main(int argc, char **argv)
{
	t_mlx				mlx_data;
	t_world				world;

	ft_bzero(&world, sizeof(t_world));
	parse(&world, argc, argv);
	parsing_exit(&world);
	exit (0);
	printf("\n");
	
	ft_bzero(&mlx_data, sizeof(t_mlx));
	if (!init_mlx(&mlx_data))
	{
		free_objects(&world.objects);
		return (1);
	}

	mlx_data.world = &world; // added world to data struct for the keyhooks, for now

	hooks(&mlx_data);
	debugger(BLU "\nstart render\n"RESET);
	render(&mlx_data, world.cam, &world);
	printf("DONE\n");
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.window, mlx_data.img1.image, 0, 0);
	mlx_loop(mlx_data.mlx);
	
	free_mlx(&mlx_data);
	free_lights(&world.lights);
	free_objects(&world.objects);
}