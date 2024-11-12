/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:06:00 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/12 13:46:00 by maraasve         ###   ########.fr       */
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

// void	render(t_mlx *data, t_world *world)
// {
// 	t_ray			ray;
// 	t_tuple			target;
// 	t_color			color;
// 	t_color			sample;
// 	float			wall_z = 30;
// 	float			wall_size = 7.0;
// 	float			aspect_ratio = (float)WIDTH / (float)HEIGHT;;
// 	float			pixel_size = wall_size / HEIGHT;
// 	float			half_height = wall_size / 2;
// 	float			half_width = half_height * aspect_ratio;
// 	float			world_y;
// 	float			world_x;
// 	float			sworld_y;
// 	float			sworld_x;
// 	float			offset = pixel_size / 2;
// 	int				x;
// 	int				y;
// 	int				sx;
// 	int				sy;
// 	int				remaining;

// 	ray.origin = create_point(-5, 0, 20);
// 	y = 0;
// 	while (y < HEIGHT)
// 	{
// 		world_y = half_height - pixel_size * y;
// 		x = 0;
// 		while (x < WIDTH)
// 		{
// 			world_x = -half_width + pixel_size * x;
// 			color = new_color(0, 0 , 0);

// 			sx = 0;
// 			while (sx < 3)
// 			{

// 				sy = 0;
// 				while (sy < 3)
// 				{
// 					sworld_x = world_x + (sx * offset);
// 					sworld_y = world_y + (sy * offset);

// 					target = create_point(sworld_x, sworld_y, wall_z);
// 					ray.direction = normalize(subtract_tuple(target, ray.origin));

// 					remaining = 5;
// 					sample = color_at(world, ray, &remaining);

// 					color = add_colors(color, sample);
// 					sy++;
// 				}
				
// 				sx++;
// 			}
// 			color = colors_multi_scalar(color, 1.0 / 9);
// 			pixel_put(data, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

int	main(void)
{
	t_mlx				mlx_data;
	t_world				world;
	t_transformation	transform;

	ft_bzero(&world, sizeof(t_world));

	t_sphere *sphere = new_sphere();
	transform.rotate = create_identity_matrix();
	transform.scale = scale_matrix(20,20,20);
	transform.translation = translation_matrix(0, 0.5, -3);
	add_object_to_list(&world.objects, new_object(SPHERE, default_material(), transformation_matrix(transform), (void *)sphere));
	free_transformation_matrix(&transform);
	
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

	t_plane *plane2 = new_plane(create_vector(0, 1, 0));
	transform.rotate = create_identity_matrix();
	transform.scale = create_identity_matrix();
	transform.translation = translation_matrix(0, -5, 0);
	add_object_to_list(&world.objects, new_object(PLANE, default_material(), transformation_matrix(transform), (void *)plane2));
	free_transformation_matrix(&transform);

	world.objects->material.color = new_color(0, 0, 255);
	world.objects->next->material.color = new_color(255, 0, 0);
	//world.objects->next->next->material.color = new_color(1, 1, 1);

	//world.lights = NULL;
	add_light_to_list(&world.lights, new_light(create_point(-40, 0, 30), new_color(255, 255, 255), 0.5));
	//add_light_to_list(&world.lights, new_light(create_point(2, 10, -30), new_color(255, 255, 255), 0.7));
	// add_light_to_list(&world.lights, new_light(create_point(-40, 50, -5), new_color(1, 1, 1), 1));
	world.ambient = new_color(255, 255, 255);
	world.ambientf = 0.6;

	t_matrix view_transform = view_transformation(create_point(0, 0, 30), create_vector(0, 0, 1), create_vector(0, 1, 0));
	t_camera camera = new_camera(HEIGHT, WIDTH, degrees_to_radians(90), view_transform);

	if (!init_mlx(&mlx_data))
	{
		free_objects(&world.objects);
		return (1);
	}
	
	hooks(&mlx_data);
	render(&mlx_data, camera, &world);
	printf("DONE\n");
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.window, mlx_data.image, 0, 0);
	mlx_loop(mlx_data.mlx);
	
	free_mlx(&mlx_data);
	free_lights(&world.lights);
	free_objects(&world.objects);
	free_matrix(camera.tranformation.grid, 4);
	free_matrix(camera.inverse->grid, 4);
}