#ifndef HITTABLE_H
#define HITTABLE_H

#include <rt.h>
#include "material.h"

enum e_hittypes
{
	sphere
};

typedef struct s_interval t_interval;

typedef struct s_hitrecord
{
	t_vec3	p;
	t_vec3	normal;
	double	t;
	int		front_face;
	t_material mat;
}t_hitrecord;

typedef struct s_hittable t_hittable;

typedef struct s_hittable
{
	int		type;
	t_vec3	center;
	double	radius;
	t_material mat;
	t_aabb bbox;
	t_hittable *next;
}t_hittable;

int hit(t_hittable *world, t_ray ray, t_interval ray_i, t_hitrecord *rec);
int hit_check(t_hittable *world, t_ray ray, t_interval ray_i, t_hitrecord*rec);
void set_face_normal(t_hitrecord **rec, const t_ray *ray, t_vec3 *outward_normal);
int	lstsize(t_hittable *lst);
void	lstadd_back(t_hittable	**lst, t_hittable	*new);
void	lstadd_front(t_hittable	**lst, t_hittable	*new);
int	lstadd(t_hittable **hittables, t_hittable *new_obj);
void	lstclear(t_hittable	**lst);
void	lstdelone(t_hittable	*lst);
t_hittable	*lstlast(t_hittable	*lst);
void	lstprint(t_hittable *lst);
t_hittable	*lstnew(int type, t_vec3 center, double radius, t_material mat);

#endif
