/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:11:28 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/11 13:11:28 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_num(char *str)
{
	char	*regex;
	int		i;

	i = 0;
	regex = "-0123456789";
	while (*str)
	{
		i = 0;
		while (regex[i] != '\0')
		{
			if (regex[i] == *str)
				break ;
			i++;
		}
		if (regex[i] == '\0' && regex[i - 1] != *str)
			return (-1);
		str++;
	}
	return (0);
}
