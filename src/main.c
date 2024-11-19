/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/30 17:06:00 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/19 19:05:53 by spenning      ########   odam.nl         */
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



float min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

float max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}
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

bool isleaf(unsigned int tricount)
{
	return (tricount > 0);
}

void intersect_tri(t_fray *ray, t_tri * tri)
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
	edge2 = tri->vertex2 - tri->vertex0;
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

void update_nodebounds(t_world *world, unsigned int node_i)
{
	t_bvh			node;
	unsigned int	first;
	unsigned int	i;
	t_tri			leaftri;

	i = 0;
	node = world->bvh[node_i];
	node.aabb_min = fvec(1e30f);
	node.aabb_max = fvec(-1e30f);
	first = node.left_first;
	while (i < node.tri_Count)
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

void swap(unsigned int *a, unsigned int *b)
{
	unsigned int *c;

	c = 0;
	*c = *a;
	*a = *b;
	*b = *c;
}

bool intersect_aabb(t_fray *ray, t_fvec bmin, t_fvec bmax)
{
	float tx1;
	float tx2;
	float tmin;
	float tmax;
	float ty1;
	float ty2;
	float tz1;
	float tz2;

	tx1 = (bmin[0] - ray->origin[0]) / ray->direction[0];
	tx2 = (bmax[0] - ray->origin[0]) / ray->direction[0];
	tmin = min(tx1, tx2);
	tmax = max(tx1, tx2);
	ty1 = (bmin[1] - ray->origin[1]) / ray->direction[1];
	ty2 = (bmax[1] - ray->origin[1]) / ray->direction[1];
	tmin = max(tmin, min(ty1, ty2));
	tmax = min(tmax, max(ty1, ty2));
	tz1 = (bmin[2] - ray->origin[2]) / ray->direction[2];
	tz2 = (bmax[2] - ray->origin[2]) / ray->direction[2];
	tmin = max(tmin, min(tz1, tz2));
	tmax = min(tmax, max(tz1, tz2));
	return (tmax >= tmin && tmin < ray->t);
}

void intersect_bvh(t_world *world, t_fray *ray, unsigned int node_i)
{
	t_bvh	node;

	node = world->bvh[node_i];
	if (!intersect_aabb(ray, node.aabb_min, node.aabb_max))
		return ;
	if (isleaf(node.tri_Count))
	{
		for (unsigned int i = 0; i < node.tri_Count; i++)
			intersect_tri(ray, &world->tri[world->tri_index[node.left_first + 1]]);
	}
	else
	{
		intersect_bvh(world, ray, node.left_first);
		intersect_bvh(world, ray, node.left_first + 1);
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
	unsigned int		left_count;
	int		left_child_index;
	int		right_child_index;

	axis = 0;
	//terminate recursion
	node = world->bvh[node_i];
	if (node.tri_Count <= 2)
		return;
	//determine split axis and position
	extent = node.aabb_max - node.aabb_min;
	if (extent[1] > extent[0])
		axis = 1;
	if (extent[2] > extent[axis])
		axis = 2;
	splitpos = node.aabb_min[axis] + extent[axis] * 0.5f;
	// in-place partition
	i = node.left_first;
	j = i + node.tri_Count - 1;
	while (i <= j)
	{
		if (world->tri[i].centroid[axis] < splitpos)
			i++;
		else
			swap(&world->tri_index[i], &world->tri_index[j--]);
	}
	//abort split if one side is empty
	left_count = i - node.left_first;
	if (left_count == 0 || left_count == node.tri_Count)
		return ;
	// create childnodes
	left_child_index = world->node_used++;
	right_child_index = world->node_used++;
	world->bvh[left_child_index].left_first = node.left_first;
	world->bvh[left_child_index].tri_Count = left_count;
	world->bvh[right_child_index].left_first = i;
	world->bvh[right_child_index].tri_Count = node.tri_Count - left_count;
	node.left_first = left_child_index;
	node.tri_Count = 0;
	update_nodebounds(world, left_child_index);
	update_nodebounds(world, right_child_index);
	//recurse
	subdivide(world, left_child_index);
	subdivide(world, right_child_index);
}


void buildbvh(t_world *world)
{
	t_bvh	root;
	t_tri	tri;
	int		i;

	i = 0;
	while (i < world->obj_count)
	{
		tri = world->tri[i];
		tri.centroid = (tri.vertex0 + tri.vertex1 + tri.vertex2) * 0.3333f;
		world->tri_index[i] = i;
		i++;
	}
	world->node_used = 1;
	root = world->bvh[0];
	root.left_first = 0;
	root.tri_Count = world->obj_count;
	update_nodebounds(world, 0);
	subdivide(world, 0);
}


void basicbvh_app(t_world *world)
{
	int		i;
	t_fvec	r0;
	t_fvec	r1;
	t_fvec	r2;

	i = 0;
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
	buildbvh(world);
}

float	magnitude(t_fvec vector)
{
	float	magnitude;

	magnitude = sqrtf(powf(vector[0], 2) + powf(vector[1], 2) \
				+ powf(vector[2], 2) + powf(vector[3], 2));
	return (magnitude);
}


t_fvec	normalize_fvec(t_fvec vector)
{
	t_fvec	normalized;
	float	mag;

	mag = magnitude(vector);
	normalized[0] = vector[0] / mag;
	normalized[1] = vector[1] / mag;
	normalized[2] = vector[2] / mag;
	normalized[3] = vector[3] / mag;
	return (normalized);
}

void write_color(t_fvec vec3)
{
	int rbyte;
	int gbyte;
	int bbyte;
	static t_interval intensity;
	intensity = inv(0.000, 0.999);
	rbyte = (int)256*(clamp(intensity, vec3[0]));
	gbyte = (int)256*(clamp(intensity, vec3[1]));
	bbyte = (int)256*(clamp(intensity, vec3[2]));
	printf("%d %d %d\n", rbyte, gbyte, bbyte);
}


int	main(int argc, char **argv)
{
	t_mlx				mlx_data;
	t_world				world;
	t_fvec				pixelpos;
	t_fvec				campos;
	t_fvec				p0;
	t_fvec				p1;
	t_fvec				p2;
	t_fray				ray;
	

	ft_bzero(&world, sizeof(t_world));
	parse(&world, argc, argv);
	debugger(BLU "amount of objects parsed: %d\n" RESET, world.obj_count);
	debugger(BLU "creating bvh\n" RESET);
	world.bvh = bvh_node(world.objects_arr, 0, world.obj_count);
	world.obj_count = 64;
	world.bvh = ft_calloc(sizeof(t_bvh), world.obj_count * 2 - 1);
	world.tri = ft_calloc(sizeof(t_tri), world.obj_count);
	world.tri_index = ft_calloc(sizeof(unsigned int), world.obj_count);

	campos = fvec3(0,0,-18);
	p0 = fvec3(-1, 1, 15);
	p1 = fvec3(1, 1, -15);
	p2 = fvec3(-1, -1, -15);
	// render
	printf("P3\n");
	printf("%d ", 640);
	printf("%d", 640);
	printf("\n255\n");
	for (int y = 0; y < 640; y++)
	{
		for (int x = 0; x < 640; x++)
		{
			pixelpos = p0 + (p1 - p0) * (x /640.0f) + (p2 - p0) * (y / 640.0f);
			ray.origin = campos;
			ray.direction = normalize_fvec(pixelpos - ray.origin);
			ray.t = 1e30f;
			intersect_bvh(&world, &ray, 0);
			if (ray.t < 1e30f)
				printf("%d %d %d\n", 255, 255, 255);
		}
		
	}
	

	exit (0);
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