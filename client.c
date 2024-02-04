/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:50:22 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/10 15:50:22 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_len(int pid, char *str)
{
	int	bits;
	int	len;

	bits = 31;
	len = ft_strlen(str);
	while (bits >= 0)
	{
		if ((len >> bits & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bits--;
		usleep(100);
	}
}

void	send_bits(char *str, int pid)
{
	int	i;
	int	bits;

	i = 0;
	bits = 7;
	send_len(pid, str);
	while (str[i] != '\0')
	{
		while (bits >= 0)
		{
			if ((str[i] >> bits & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bits--;
			usleep(100); //80
		}
		bits = 7;
		i++;
	}
}

void	recived(int sig)
{
	(void)sig;
	ft_putstr_fd(C_GREEN"RECIVED !", 1);
	ft_putstr_fd(C_RESET"\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd(C_RED"ERROR! ", 1);
		ft_putstr_fd(C_RESET"The client takes two parameters:\n", 1);
		ft_putstr_fd("./client <PID> <STRING>", 1);
	}
	else
	{
		if (is_num(argv[1]) == -1)
		{
			ft_putstr_fd(C_RED"ERROR! ", 1);
			ft_putstr_fd(C_RESET"The PID its not correct!\n", 1);
		}
		if (ft_strlen(argv[2]) < 1)
		{
			ft_putstr_fd(C_RED"ERROR! ", 1);
			ft_putstr_fd(C_RESET"Write a message with content!\n", 1);
		}
		signal(SIGUSR2, recived);
		send_bits(argv[2], ft_atoi(argv[1]));
	}
	return (0);
}
