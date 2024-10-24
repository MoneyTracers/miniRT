#ifndef INTERVAL_H
#define INTERVAL_H

#include <rt.h>

typedef struct s_interval
{
	double min;
	double max;
} t_interval;


double size(t_interval inv);
int contains(t_interval inv, double x);
int surround(t_interval inv, double x);
t_interval dinv(void);
t_interval inv(double min, double max);
double clamp(t_interval inv, double x);
t_interval inv_inv(t_interval a, t_interval b);
t_interval axis_interval(t_aabb aabb, int n);

#endif

