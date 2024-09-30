/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printftests_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 07:11:57 by mynodeus          #+#    #+#             */
/*   Updated: 2024/05/17 07:23:03 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printftests.h"

int	log_int(int test_count, FILE *errorlog, int result_org, int result_ft)
{
	printf(RED "%d FAIL "RESET, test_count);
	fprintf(errorlog, "error\n");
	fprintf(errorlog, "test number: %d\n", test_count);
	fprintf(errorlog, "org: %d\n", result_org);
	fprintf(errorlog, "ft: %d\n", result_ft);
	fprintf(errorlog, "---------\n");
	return (1);
}

int	comparefile(FILE *fptr1, FILE *fptr2, int *line, int *col)
{
	char	ch1;
	char	ch2;

	ch1 = 0;
	ch2 = 0;
	*line = 1;
	*col = 0;
	while (ch1 != EOF && ch2 != EOF)
	{
		ch1 = fgetc(fptr1);
		ch2 = fgetc(fptr2);
		if (ch1 == '\n')
		{
			*line += 1;
			*col = 0;
		}
		if (ch1 != ch2)
			return (-1);
		*col += 1;
	}
	if (ch1 == EOF && ch2 == EOF)
		return (0);
	else
		return (-1);
}

int	compare_length(int test_count, int ft_outcome, int outcome)
{
	FILE	*errorlog;

	errorlog = fopen("logs/error_log.txt", "a");
	if (errorlog == NULL)
	{
		printf("Error opening log file\n");
		return (1);
	}
	if (ft_outcome != outcome)
		log_int(test_count, errorlog, outcome, ft_outcome);
	fclose(errorlog);
	return (ft_outcome - outcome);
}

int	compare_files(int test_count)
{
	int		line;
	int		col;
	FILE	*fptr1;
	FILE	*fptr2;
	FILE	*errorlog;

	fptr1 = fopen("ft_temp.txt", "r");
	fptr2 = fopen("temp.txt", "r");
	errorlog = fopen("logs/error_log.txt", "a");
	if (fptr1 == NULL || fptr2 == NULL || errorlog == NULL)
	{
		printf("Error opening log file\n");
		return (1);
	}
	rewind(fptr1);
	rewind(fptr2);
	if (comparefile(fptr1, fptr2, &line, &col) != 0)
		log_int(test_count, errorlog, line, col);
	fclose(fptr1);
	fclose(fptr2);
	fclose(errorlog);
	return (0);
}
