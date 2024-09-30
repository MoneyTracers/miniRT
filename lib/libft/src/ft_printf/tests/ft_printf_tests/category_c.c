/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   category_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 07:59:20 by mynodeus          #+#    #+#             */
/*   Updated: 2024/05/17 08:16:52 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printftests.h"

void	category_c(void)
{
	int	test_count;

	test_count = 1;
	printf(BMAG "\n%%c\n" RESET);
	test_count = test_util(test_count, "lol %c", '1');
	test_count = test_util(test_count, "lol %c", 'w');
	test_count = test_util(test_count, "%c%c%c", '\0', 'l', -42);
	test_count = test_util(test_count, "%c%c%c", 23647238, 265, -42);
	test_count = test_util(test_count, "%c%c%c", 0, -1, 0);
	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}
