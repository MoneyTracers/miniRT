/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:06:00 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/29 14:08:04 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

void	render(t_data *data, t_world *world)
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
			color = color_at(world, ray);
			color = add_colors(color, colors_multi_scalar(world->ambient, world->ambientf));
			free_intersection(&world->intersections);
			free_intersection(&world->shadow_intersections);
			pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}


int main(void)
{
	t_data				data;
	t_world				world;
	t_object			*sphere;
	t_object			*cylinder;
	t_transformation	transformation;
	t_object			*plane;
	t_object			*plane2;
	t_ray				ray;

	transformation.scale = scale_matrix(0.9, 0.9, 0.9);
	transformation.translation = translation_matrix(-1, -0.6, 5);
	transformation.rotate = create_identity_matrix();
	sphere = new_object(create_point(0, 0, 0), 1, default_material(), new_object_base(SPHERE, transformation_matrix(transformation)));
	if (!sphere)
		return (1);

	free_transformation_matrix(&transformation);
	transformation.scale = create_identity_matrix();
	transformation.translation = translation_matrix(0, -1.5, 0);
	transformation.rotate = create_identity_matrix();
	plane = new_object(create_point(0,0,0), 0, default_material(), new_object_base(PLANE, transformation_matrix(transformation)));
	if (!plane)
		return (2);
	
	free_transformation_matrix(&transformation);
	transformation.scale = create_identity_matrix();
	transformation.translation = translation_matrix(0, 100, 0);
	transformation.rotate = rotate(M_PI / 2, 0, 0);
	plane2 = new_object(create_point(0,0,0), 0, default_material(), new_object_base(PLANE, transformation_matrix(transformation)));
	if (!plane2)
		return (2);

	free_transformation_matrix(&transformation);
	transformation.scale = scale_matrix(1, 1, 1);
	transformation.translation = translation_matrix(1, -2, 8);
	transformation.rotate = rotate(0, 0, 0);
	cylinder = new_object(create_point(0,0,0), 0, default_material(), new_object_base(CYLINDER, transformation_matrix(transformation)));
	if (!plane)
		return (2);
	free_transformation_matrix(&transformation);

	sphere->material.color = new_color(1.0, 0.6, 0.8);
	plane->material.color = new_color(0.2, 0.6, 0.6);
	plane2->material.color = new_color(0.2, 0.6, 0.6);
	cylinder->material.color = new_color(0.3, 0.5, 0.8);
	cylinder->cyl_max = 3;
	cylinder->cyl_min = 0;
	cylinder->cyl_capped = true;
	plane->material.ambient = 0.6;
	plane->material.diffuse = 0.3;
	plane->material.specular = 0.3;
	world.shapes = NULL;
	add_shape_to_list(&world.shapes, sphere);
	add_shape_to_list(&world.shapes, plane);
	add_shape_to_list(&world.shapes, plane2);
	add_shape_to_list(&world.shapes, cylinder);
	
	world.light = new_light(create_point(-10, -2, -50), new_color(1, 1, 1));
	world.ambient = new_color(0.3, 0.1, 0.5);
	world.ambientf = 0.2;

	world.intersections = NULL;
	world.shadow_intersections = NULL;

	ray.direction = create_vector(0,0,1);
	ray.origin = create_point(0, 0, -5);

	if (!init_mlx(&data))
		return (1);
	hooks(&data);
	render(&data, &world);
	mlx_put_image_to_window(data.mlx, data.window, data.image, 0, 0);
	mlx_loop(data.mlx);
	free_mlx(&data);

	free_shapes(&world.shapes);
}
