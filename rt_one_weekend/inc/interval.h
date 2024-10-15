#ifndef INTERVAL_H
#define INTERVAL_H


typedef struct s_interval
{
	double min;
	double max;
} t_interval;


double size(t_interval inv);
int contains(t_interval inv, double x);
int surround(t_interval inv, double x);
t_interval dinv(double min, double max);
t_interval inv(double min, double max);


#endif

