/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/30 17:06:00 by maraasve      #+#    #+#                 */
/*   Updated: 2024/12/03 18:27:32 by spenning      ########   odam.nl         */
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

void	parsing_exit_message(t_world *world)
{
	if (world->exit_code)
		write(2, "Error\n", 6);
	if (world->err == GNL)
		perror("gnl error");
	else if (world->err == CLOSE)
		perror("close error");
	else if (world->err == INC_FORMAT)
		write(2, "incorrect format in file\n", 25);
	else if (world->err == L_IDENTIFIER)
		write(2, "too many lights in .rt\n", 23);
	else if (world->err == A_IDENTIFIER)
		write(2, "too many ambient light objects in .rt\n", 38);
	else if (world->err == C_IDENTIFIER)
		write(2, "too many camera's in .rt\n", 25);
	else if (world->err == OBJECT)
		write(2, "error in allocation for object\n", 31);
	else if (world->err == LIGHT)
		write(2, "error in allocation for light\n", 30);
	else if (world->err == NORMAL)
		write(2, "vector not normalized\n", 22);
}

void	parsing_exit(t_world *world)
{
	parsing_exit_message(world);
	if (world->exit_code)
	{
		free_objects(&world->objects);
		free_lights(&world->lights);
		exit(world->exit_code);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_mlx				mlx_data;
	t_world				world;

	ft_bzero(&world, sizeof(t_world));
	parse(&world, argc, argv);
	parsing_exit(&world);
	ft_bzero(&mlx_data, sizeof(t_mlx));
	if (!init_mlx(&mlx_data))
	{
		free_objects(&world.objects);
		return (1);
	}
	mlx_data.world = &world;
	world.mlx_data = &mlx_data;
	hooks(&mlx_data);
	debugger(BLU "\nstart render\n"RESET);
	render(&mlx_data, world.cam, &world);
	printf("DONE\n");
	mlx_put_image_to_window(mlx_data.mlx, \
	mlx_data.window, mlx_data.img1.image, 0, 0);
	mlx_loop(mlx_data.mlx);
	free_mlx(&mlx_data);
	free_lights(&world.lights);
	free_objects(&world.objects);
}
