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
static int	g_pid = 0;
static int	j = 0;

#include <stdio.h>
void	receive_bits(int bit, siginfo_t *info, void *context)
{
	static int	i = 0;
	static int	flag = 1;
	static char	whole_c = 0;
	static char	*result = NULL;
	(void)context;
	if (flag == 1)
	{
		add_bits(bit, &whole_c, &g_int_nb, 0);
		if (++i == 32)
		{
			if (add_memory(&i, &flag, &g_int_nb, &result) == -1)
				return ;
			i = 0;
			flag = 2;
		}
		else
			flag = 1;
	}
	else if (flag == 2)
	{

		// write(1, ft_itoa(bit),1);
		// write(1, ft_itoa(g_pid),5);
		// write(1, "\n",1);
		add_bits(bit, &whole_c, &g_pid, 0);
		if (++i == 32)
		{
			i = 0;
			flag = 0;
			// write(1, "LAST\n",6);
			// write(1, ft_itoa(g_pid),5);
		}
		else
			flag = 2;
		// write(1, ft_itoa(flag),1);
		// write(1, "\n",1);
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
			kill(info -> si_pid, SIGUSR1);
			// kill(g_pid, SIGUSR1);
			g_pid = 0;
		}
		else
			flag = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	struct sigaction	sigact;
	sigact.sa_sigaction = receive_bits;
	sigact.sa_flags = 0;
	ft_putstr_fd("PID: "C_GREEN, 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(C_RESET"", 1);
	ft_putstr_fd("\nWaiting for a signal ...\n", 1);
	if (argc == 1)
	{
		sigaction(SIGUSR2, &sigact, NULL);
		sigaction(SIGUSR1, &sigact, NULL);
	}
	// struct sigaction	sigact;
	// sigact.sa_sigaction = (void *)receive_bits;
	// sigact.sa_flags = 0;
	// sigaction(SIGUSR1, &sigact, NULL);
	// sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
	return (0);
}
