/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/30 17:06:00 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/19 17:20:06 by spenning      ########   odam.nl         */
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
#include <bvh.h>



float	fvec_dot(t_fvec vector1, t_fvec vector2)
{
	float	dot_product;

	dot_product = vector1[0] * vector2[0] \
				+ vector1[1] * vector2[1] \
				+ vector1[2] * vector2[2] \
				+ vector1[3] * vector2[3];
	return (dot_product);
}

t_fvec	fvec_cross(t_fvec vector1, t_fvec vector2)
{
	t_fvec	cross_product;

	cross_product[0] = vector1[1]* vector2[2] \
							- vector1[2] * vector2[1];
	cross_product[1] = vector1[2] * vector2[0] \
							- vector1[0] * vector2[2];
	cross_product[2] = vector1[0] * vector2[1] \
							- vector1[1] * vector2[0];
	cross_product[3] = 0.0;
	return (cross_product);
}


t_fvec fvec3(float x, float y, float z)
{
	t_fvec a = {x, y, z, 0};
	return (a);
}

t_fvec fvec(float i)
{
	t_fvec a = {i, i, i, i};
	return (a);
}
t_fvec fvecminf( t_fvec a, t_fvec b )
{ 
	return fvec3( fminf( a[0], b[0] ), fminf( a[1], b[1] ), fminf( a[2], b[2] ) );
}

t_fvec fvecmaxf( t_fvec a, t_fvec b )
{ 
	return fvec3( fmaxf( a[0], b[0] ), fmaxf( a[1], b[1] ), fmaxf( a[2], b[2] ) );
}


void update_nodebounds(t_world *world, unsigned int node_i)
{
	t_bvh			node;
	unsigned int	first;
	int				i;
	t_tri			leaftri;

	i = 0;
	node = world->bvh[node_i];
	node.aabb_min = fvec(1e30f);
	node.aabb_max = fvec(-1e30f);
	first = node.first_prim;
	while (i < node.prim_count)
	{
		leaftri = world->tri[first + i];
		node.aabb_min = fvecminf(node.aabb_min, leaftri.vertex0);
		node.aabb_min = fvecminf(node.aabb_min, leaftri.vertex1);
		node.aabb_min = fvecminf(node.aabb_min, leaftri.vertex2);
		node.aabb_max = fvecminf(node.aabb_max, leaftri.vertex0);
		node.aabb_max = fvecminf(node.aabb_max, leaftri.vertex1);
		node.aabb_max = fvecminf(node.aabb_max, leaftri.vertex2);
		i++;
	}
}


void subdivide(t_world *world, unsigned int node_i)
{
	t_bvh	node;
	t_fvec	extent;
	int		axis;
	float	splitpos;
	int		i;
	int		j;
	int		left_count;
	int		left_child_index;
	int		right_child_index;

	axis = 0;
	node = world->bvh[node_i];
	extent = node.aabb_max - node.aabb_min;
	if (extent[1] > extent[0])
		axis = 1;
	if (extent[2] > extent[axis])
		axis = 2;
	splitpos = node.aabb_min[axis] + extent[axis] * 0.5f;
	i = node.first_prim;
	j = i + node.prim_count - 1;
	while (i <= j)
	{
		// if triangle centroid bigger than split position 
		// i++
		// else
		// swap triangles
	}
	left_count = i - node.first_prim;
	if (left_count == 0 || left_count == node.prim_count)
		return ;
	left_child_index = world->node_used++;
	right_child_index = world->node_used++;
	node.left_child = left_child_index;
	world->bvh[left_child_index].first_prim = node.first_prim;
	world->bvh[left_child_index].prim_count = left_count;
	world->bvh[right_child_index].first_prim = i;
	world->bvh[right_child_index].prim_count = node.prim_count - left_count;
	node.prim_count = 0;
}


void buildbvh(t_world *world)
{
	t_bvh root;

	world->node_used = 1;
	root = world->bvh[0];
	root.prim_count = world->obj_count;
	update_nodebounds(world, 0);
	subdivide(world, 0);
}

float min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

void intersect_tri(t_ray *ray, t_tri * tri)
{
	t_fvec edge1;
	t_fvec edge2;
	t_fvec h;
	float a;
	float f;
	float u;
	float v;
	float t;
	t_fvec s;
	t_fvec q;

	edge1 = tri->vertex1 - tri->vertex0;
	edge1 = tri->vertex2 - tri->vertex0;
	h = fvec_cross(ray->direction, edge2);
	a = fvec_dot(edge1, h);
	if (a > -0.0001f && a < 0.0001f)
		return;
	f = 1 / a;
	s = ray->origin - tri->vertex0;
	u = f * fvec_dot(s, h);
	if (u < 0 || u > 1)
		return;
	q = fvec_cross(s, edge1);
	v = f * fvec_dot(ray->direction, q);
	if (v < 0 || u + v > 1)
		return ;
	t = f * fvec_dot(edge2, q);
	if (t > 0.0001f)
		ray->t = min(ray->t, t);
}

void basicbvh_app(t_world *world)
{
	int		i;
	t_fvec	r0;
	t_fvec	r1;
	t_fvec	r2;

	while (i < world->obj_count)
	{
		r0 = fvec3(rand(), rand(), rand());
		r1 = fvec3(rand(), rand(), rand());
		r2 = fvec3(rand(), rand(), rand());
		world->tri[i].vertex0 = r0 * 9 - fvec(5);
		world->tri[i].vertex1 = world->tri[i].vertex0 + r1;
		world->tri[i].vertex2 = world->tri[i].vertex0 + r2;
		i++;
	}
}


int	main(int argc, char **argv)
{
	t_mlx				mlx_data;
	t_world				world;

	ft_bzero(&world, sizeof(t_world));
	parse(&world, argc, argv);
	debugger(BLU "amount of objects parsed: %d\n" RESET, world.obj_count);
	debugger(BLU "creating bvh\n" RESET);
	world.bvh = bvh_node(world.objects_arr, 0, world.obj_count);
	world.bvh = ft_calloc(sizeof(t_bvh), world.obj_count * 2 - 1);
	world.tri = ft_calloc(sizeof(t_tri), world.obj_count);
	void buildbvh(&world);
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