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
		usleep(80);
	}
}

void	send_pid(int pid, int send)
{
	int	bits;

	bits = 31;
	while (bits >= 0)
	{
		if ((send >> bits & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bits--;
		usleep(80);
	}
}

#include <stdio.h>

void	send_bits(char *str, int pid)
{
	int	i;
	int	bits;

	i = 0;
	bits = 7;
	send_len(pid, str);
	// printf("PID: %i", getpid());
	send_pid(pid, getpid());
	while (str[i] != '\0')
	{
		while (bits >= 0)
		{
			if ((str[i] >> bits & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bits--;
			usleep(80);
		}
		bits = 7;
		i++;
	}
}


void received(int signo)
{
    // Manejar la señal recibida
    if (signo == SIGUSR1)
        write(1, "BIEN !!!!\n", 11);
    else if (signo == SIGUSR2)
        write(1, "Error: Not received confirmation signal.\n", 41);
    else
        perror("Error receiving signal");
}

// int main(int argc, char **argv)
// {
//     if (argc != 3)
//     {
//         ft_putstr_fd(C_RED"ERROR! ", 1);
//         ft_putstr_fd(C_RESET"The client takes two parameters:\n", 1);
//         ft_putstr_fd("./client <PID> <STRING>\n", 1);
//         return 1;  // Retorna un código de error
//     }

//     int server_pid = ft_atoi(argv[1]);
//     if (server_pid <= 0)
//     {
//         ft_putstr_fd(C_RED"ERROR! ", 1);
//         ft_putstr_fd(C_RESET"The PID is not valid!\n", 1);
//         return 1;  // Retorna un código de error
//     }

//     if (ft_strlen(argv[2]) < 1)
//     {
//         ft_putstr_fd(C_RED"ERROR! ", 1);
//         ft_putstr_fd(C_RESET"Write a message with content!\n", 1);
//         return 1;  // Retorna un código de error
//     }

//     signal(SIGUSR1, received);

//     // Añade una pausa antes de enviar señales al servidor
//     usleep(500000);  // Pausa de 0.5 segundos

//     send_bits(argv[2], server_pid);

//     return 0;  // Retorna éxito
// }

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
		else if (ft_strlen(argv[2]) < 1)
		{
			ft_putstr_fd(C_RED"ERROR! ", 1);
			ft_putstr_fd(C_RESET"Write a message with content!\n", 1);
		}
		else
		{
			signal(SIGUSR1, received);
			send_bits(argv[2], ft_atoi(argv[1]));
		}
	}
	return (0);
}
