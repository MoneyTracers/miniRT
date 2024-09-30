/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 07:56:53 by mynodeus          #+#    #+#             */
/*   Updated: 2024/05/17 07:58:17 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printftests.h"
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

int	test_util(int tc, char *format, ...)
{
	int		org;
	int		ft;
	va_list	ptr;

	org = 0;
	ft = 0;
	va_start(ptr, format);
	freopen("ft_temp.txt", "w", stdout);
	ft = ft_printf(format, ptr);
	freopen("temp.txt", "w", stdout);
	org = printf(format, ptr);
	freopen("/dev/tty", "w", stdout);
	if (compare_length(tc, ft, org) != 0 || compare_files(tc) != 0)
		printf(RED "%d FAIL "RESET, tc);
	else
		printf(GRN "%d OK " RESET, tc);
	va_end(ptr);
	return (tc++);
}
