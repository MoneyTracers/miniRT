#include <rt.h>


t_aabb sphere_bbox(t_vec3 center, double radius)
{
	t_vec3 rvec;
	rvec = vec(radius, radius, radius);
	return (aabb_vec(vec_sub(center, rvec), vec_add(center, rvec)));
}


t_hittable **array_add(t_hittable **arr, int type, t_vec3 center, double radius, t_material mat)
{
	t_hittable **new_arr;
	t_hittable *new_node;
	size_t len;
	int index;

	index = 0;
	len = 0;
	while (arr[len] != NULL)
	{
		len++;
	}
	len += 1;
	printf("len %lu\n", len);
	new_arr = calloc(1, len * sizeof(t_hittable));
	if (new_arr == NULL)
		return (NULL);
	while (index < (int)len - 1)
	{
		printf("index in loop %d\n", index);
		new_arr[index] = arr[index];
		index++;
	}
	new_node = calloc(sizeof(t_hittable), 1);
	if (new_node == NULL)
		return (NULL);
	if (type == sphere)
		new_node->bbox = sphere_bbox(center, radius);
	new_node->type = type;
	new_node->center = center;
	new_node->radius = radius;
	new_node->mat = mat;
	new_node->next = NULL;
	new_arr[index] = new_node;
	new_arr[len] = NULL;
	free(arr);
	for (int i = 0; i <= index; i++)
	{
		printf("new arr %f\n", new_arr[i]->radius);
	}
	return (new_arr);
}

t_hittable	**arraynew(int type, t_vec3 center, double radius, t_material mat)
{
	t_hittable	**new_arr;
	t_hittable	*new_node;

	new_arr = calloc(sizeof(t_hittable) * 2, 1);
	new_node = calloc(sizeof(t_hittable), 1);
	if (new_node == NULL)
		return (NULL);
	if (type == sphere)
		new_node->bbox = sphere_bbox(center, radius);
	new_node->type = type;
	new_node->center = center;
	new_node->radius = radius;
	new_node->mat = mat;
	new_node->next = NULL;
	new_arr[0] = new_node;
	new_arr[1] = NULL;
	return (new_arr);
}

