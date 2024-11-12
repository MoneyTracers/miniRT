/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: marieke <marieke@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/30 17:06:00 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/12 13:50:23 by spenning      ########   odam.nl         */
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


	// t_sphere *sphere = new_sphere();
	// transform.rotate = create_identity_matrix();
	// transform.scale = scale_matrix(20,20,20);
	// transform.translation = translation_matrix(0, 0.5, -3);
	// add_object_to_list(&world.objects, new_object(SPHERE, default_material(), transformation_matrix(transform), (void *)sphere));
	// free_transformation_matrix(&transform);
	
	// t_cylinder			*cyl;
	// cyl = new_cylinder(-1, 1, true);
	// transform.rotate = create_identity_matrix();
	// transform.scale = scale_matrix(0.5, 0.5, 0.5);
	// transform.translation = translation_matrix(1, 0, 0);
	// add_object_to_list(&world.objects, new_object(CYLINDER, default_material(), transformation_matrix(transform), (void *)cyl));
	// free_transformation_matrix(&transform);

	// t_plane *plane = new_plane(create_vector(0, 0, -1));
	// transform.rotate = create_identity_matrix();
	// transform.scale = create_identity_matrix();
	// transform.translation = translation_matrix(0, 0, 5);
	// add_object_to_list(&world.objects, new_object(PLANE, default_material(), create_identity_matrix(), (void *)plane));
	// free_transformation_matrix(&transform);

	// t_plane *plane2 = new_plane(create_vector(0, 1, 0));
	// transform.rotate = create_identity_matrix();
	// transform.scale = create_identity_matrix();
	// transform.translation = translation_matrix(0, -5, 0);
	// add_object_to_list(&world.objects, new_object(PLANE, default_material(), transformation_matrix(transform), (void *)plane2));
	// free_transformation_matrix(&transform);

	// world.objects->material.color = new_color(0.7, 0.4, 0.9);
	// world.objects->next->material.color = new_color(0.1, 0.6, 0.6);
	//world.objects->next->next->material.color = new_color(1, 1, 1);

	//world.lights = NULL;
	// add_light_to_list(&world.lights, new_light(create_point(-40, 0, 30), new_color(1, 1, 1), 0.5));
	// add_light_to_list(&world.lights, new_light(create_point(2, 10, -30), new_color(1, 1,1), 0.7));
	// add_light_to_list(&world.lights, new_light(create_point(-40, 50, -5), new_color(1, 1, 1), 1));
	// world.ambient = new_color(1, 1, 1);
	// world.ambientf = 0.6;
	ft_bzero(&world, sizeof(t_world));
	parse(&world, argc, argv);
	
	if (!init_mlx(&mlx_data))
	{
		free_objects(&world.objects);
		return (1);
	}
	
	hooks(&mlx_data);
	render(&mlx_data, world.cam, &world);
	printf("DONE\n");
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.window, mlx_data.image, 0, 0);
	mlx_loop(mlx_data.mlx);
	
	free_mlx(&mlx_data);
	free_lights(&world.lights);
	free_objects(&world.objects);
	free_matrix(world.cam.tranformation.grid, 4);
	free_matrix(world.cam.inverse->grid, 4);
}