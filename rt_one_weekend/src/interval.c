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
