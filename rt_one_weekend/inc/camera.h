#ifndef CAMERA_H
#define CAMERA_H

#include <rt.h>

typedef struct s_bvh t_bvh;
typedef struct s_hittable t_hittable;


typedef struct s_camera
{
	double	aspect_ratio;
	int		image_width;
	int		image_heigth;
	int		samples_per_pixel;
	int		max_depth;
	double	pixel_samples_scale;
	double	focal_length;
	double	viewport_heigth;
	double	viewport_width;
	double	vfov;
	t_vec3	lookfrom;
	t_vec3	lookat;
	t_vec3	vup;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	center;
	t_vec3	pixel_delta_u;
	t_vec3	pixel_delta_v;
	t_vec3	viewport_upper_left;
	t_vec3	pixel00_loc;
}t_camera;

void render(t_camera *cam, t_bvh *world);

#endif
