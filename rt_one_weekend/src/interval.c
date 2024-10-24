#include <interval.h>

double size(t_interval inv)
{
	return (inv.max - inv.min);
}

int contains(t_interval inv, double x)
{
	if ((inv.min <= x) && (x <= inv.max))
		return (1);
	return (0);
}

int surround(t_interval inv, double x)
{
	if ((inv.min < x) && (x < inv.max))
		return (1);
	return (0);
}

double clamp(t_interval inv, double x)
{
	if (inv.min > x)
		return (inv.min);
	if (inv.max < x)
		return (inv.max);
	return (x);
}


t_interval dinv(void)
{
	t_interval new;

	new.min = 0;
	new.max = 0;
	return (new);
}
t_interval inv(double min, double max)
{
	t_interval new;

	new.min = min;
	new.max = max;
	return (new);
}

t_interval inv_inv(t_interval a, t_interval b)
{
	t_interval new;

	if (a.min <= b.min)
		new.min = a.min;
	else 
		new.min = b.min;
	if (a.max >= b.max)
		new.max = a.max;
	else
		new.max = b.max;
	return (new);
}