/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/30 17:06:00 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/08 11:12:56 by spenning      ########   odam.nl         */
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
#include <parse.h>

void	render(t_mlx *data, t_world *world)
{
	t_ray			ray;
	t_tuple			target;
	t_color			color;
	float			wall_z = 10;
	float			wall_size = 7.0;
	float			aspect_ratio = (float)WIDTH / (float)HEIGHT;;
	float			pixel_size = wall_size / HEIGHT;
	float			half_height = wall_size / 2;
	float			half_width = half_height * aspect_ratio;
	float			world_y;
	float			world_x;
	int				x;
	int				y;
	int				remaining;

	ray.origin = create_point(0, 0, -5);
	y = 0;
	while (y < HEIGHT)
	{
		world_y = half_height - pixel_size * y;
		x = 0;
		while (x < WIDTH)
		{
			world_x = -half_width + pixel_size * x;
			target = create_point(world_x, world_y, wall_z);
			ray.direction = normalize(subtract_tuple(target, ray.origin));
			remaining = 5;
			color = color_at(world, ray, &remaining);
			pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

int main(int argc, char **argv)
{
	t_mlx				mlx_data;
	t_world				world;

	ft_bzero(&world, sizeof(t_world));
	parse(world, argc, argv);
	// sphere = new_sphere();
	// transform.rotate = create_identity_matrix();
	// transform.scale = create_identity_matrix();
	// transform.translation = translation_matrix(-1, 0, 0);
	// add_object_to_list(&world.objects, new_object(SPHERE, default_material(), transformation_matrix(transform), (void *)sphere));
	// free_transformation_matrix(&transform);
	
	// cyl = new_cylinder(-1, 1, true);
	// transform.rotate = create_identity_matrix();
	// transform.scale = scale_matrix(0.5, 0.5, 0.5);
	// transform.translation = translation_matrix(1, 0, 0);
	// add_object_to_list(&world.objects, new_object(CYLINDER, default_material(), transformation_matrix(transform), (void *)cyl));
	// free_transformation_matrix(&transform);

	// world.objects->material.color = new_color(0.4, 0.2, 0.6);
	// world.objects->next->material.color = new_color(0.1, 0.6, 0.6);

	// world.lights = NULL;
	// add_light_to_list(&world.lights, new_light(create_point(0, 0, -5), new_color(0.8, 0.8, 0.8)));
	// add_light_to_list(&world.lights, new_light(create_point(0, 100, 0), new_color(0.5, 0.5, 0.5)));
	// add_light_to_list(&world.lights, new_light(create_point(60, 5, -100), new_color(0.5, 0.5, 0.5)));
	// world.ambient = new_color(0.5, 0.3, 0.4);
	// world.ambientf = 0.4;

	if (!init_mlx(&mlx_data))
	{
		free_objects(&world.objects);
		return (1);
	}
	hooks(&mlx_data);
	render(&mlx_data, &world);
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.window, mlx_data.image, 0, 0);
	mlx_loop(mlx_data.mlx);
	
	free_mlx(&mlx_data);
	free_lights(&world.lights);
	free_objects(&world.objects);
}