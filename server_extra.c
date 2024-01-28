/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:50:22 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/26 13:50:22 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	reset(int *int_nb, int *i, int *j, char **result)
{
	ft_putstr_fd((*result), 1);
	*int_nb = 0;
	*i = 0;
	*j = 0;
	return (1);
}

void	add_content(int *i, int *j, char **result, char *whole_c)
{
	*i = 0;
	(*result)[(*j)++] = *whole_c;
	*whole_c = 0;
}

int	add_memory(int *i, int *flag, int *int_nb, char **result)
{
	*i = 0;
	*flag = 0;
	(*result) = (char *)malloc((*int_nb + 1) * sizeof(char));
	if (!(*result))
		return (-1);
	(*result)[(*int_nb)] = '\0';
	return (0);
}

void	add_bits(int bit, char *whole_c, int *int_nb, int flag_chosen)
{
	if (flag_chosen == 0)
	{
		if (bit == SIGUSR1)
			*int_nb = (*int_nb << 1) | 1;
		else if (bit == SIGUSR2)
			*int_nb = *int_nb << 1;
	}
	else
	{
		if (bit == SIGUSR1)
			*whole_c = (*whole_c << 1) | 1;
		else if (bit == SIGUSR2)
			*whole_c = *whole_c << 1;
	}
}
