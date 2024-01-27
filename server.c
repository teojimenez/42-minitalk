/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:50:26 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/10 15:50:26 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	reset(int *int_nb, int *i, char **result)
{
	ft_putstr_fd((*result), 1);
	free((*result));
	*int_nb = 0;
	*i = 0;
	return (1);
}

void	add_content(int *i, char **result, char *whole_c)
{
	int	len;
	
	len = ft_strlen(*result);
	*i = 0;
	if(len != 0)
		++len;
	(*result)[--len] = *whole_c;
	*whole_c = 0;
}

int	add_memory(int *i, int *flag, int *int_nb, char **result)
{
	*i = 0;
	*flag = 0;
	(*result) = (char *)malloc((*int_nb + 1	) * sizeof(char));
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

void	receive_bits(int bit)
{
	static int	i = 0;
	// static int	j = 0;
	static int	flag = 1;
	static char	whole_c = 0;
	static int	int_nb;
	static char	*result = NULL;

	if (flag == 1)
	{
		add_bits(bit, &whole_c, &int_nb, 0);
		if (++i == 32)
			if (add_memory(&i, &flag, &int_nb, &result) == -1)
				return ;
	}
	else
	{
		add_bits(bit, &whole_c, &int_nb, 1);
		if (++i == 8)
			add_content(&i, &result, &whole_c);
		if (ft_strlen(result) == int_nb)
		{
			flag = reset(&int_nb, &i, &result);
			whole_c = 0;
		}
	}
}

int	main(void)
{
	ft_putstr_fd("PID: "C_GREEN, 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(C_RESET"", 1);
	ft_putstr_fd("\nWaiting for a signal ...\n", 1);
	signal(SIGUSR1, receive_bits);
	signal(SIGUSR2, receive_bits);
	while (1)
		pause();
	return (0);
}

// TODO:
// *mirar que el pid sea correcto