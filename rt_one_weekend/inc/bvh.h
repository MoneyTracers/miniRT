#ifndef BVH_H
#define BVH_H

#include <rt.h>


typedef struct s_bvh t_bvh;


typedef struct s_bvh
{
	t_bvh *left;
	t_bvh *right;
	t_hittable *object;
} t_bvh;


#endif



