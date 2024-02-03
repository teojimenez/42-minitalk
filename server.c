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

static int	g_int_nb;
static int	g_pid;

void	receive_bits(int bit)
{
	static int	i = 0;
	static int	j = 0;
	static int	flag = 1;
	static char	whole_c = 0;
	static char	*result = NULL;

	if (flag == 1)
	{
		add_bits(bit, &whole_c, &g_int_nb, 0);
		if (++i == 32)
			if (add_memory(&i, &flag, &g_int_nb, &result) == -1)
				return ;
	}
	else if (flag == 2)
	{
		add_bits(bit, &whole_c, &g_pid, 0);
		if (++i == 32)
		{
			i = 0;
			flag = 0;
		}
	}
	else
	{
		add_bits(bit, &whole_c, &g_int_nb, 1);
		if (++i == 8)
			add_content(&i, &j, &result, &whole_c);
		if (j == g_int_nb)
		{
			flag = reset(&g_int_nb, &i, &j, &result);
			free(result);
			whole_c = 0;
			kill(g_pid, SIGUSR2);
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
