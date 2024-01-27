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

// void	send_len(int pid, char *str)
// {
// 	int	bits;
// 	int	len;

// 	bits = 31;
// 	len = ft_strlen(str);
// 	while (bits >= 0)
// 	{
// 		if ((len >> bits & 1) == 1)
// 			kill(pid, SIGUSR1);
// 		else
// 			kill(pid, SIGUSR2);
// 		bits--;
// 		usleep(80);
// 	}
// }

// void	send_bits(char *str, int pid)
// {
// 	int	i;
// 	int	bits;

// 	i = 0;
// 	bits = 7;
// 	send_len(pid, str);
// 	while (str[i] != '\0')
// 	{
// 		while (bits >= 0)
// 		{
// 			if ((str[i] >> bits & 1) == 1)
// 				kill(pid, SIGUSR1);
// 			else
// 				kill(pid, SIGUSR2);
// 			bits--;
// 			usleep(80);
// 		}
// 		bits = 7;
// 		i++;
// 	}
// }

void    send_bits(char *str, int pid)
{
    int i = 0;
    int bits = 31;
    int len;
    len = ft_strlen(str);
    // char *char_nb = ft_itoa(len);
    while(bits >= 0)
    {
        if((len >> bits & 1) == 1)
            kill(pid, SIGUSR1); // -> 1
        else
            kill(pid, SIGUSR2); // -> 0
        bits--;
        usleep(80);
    }
    bits = 7;
    i = 0;
    while(str[i] != '\0')
    {
        while(bits >= 0)
        {
            //desplaza el valor de str[i] (los bits)
            //operador AND (si el ultimo bit es 1 ; true)
            if((str[i] >> bits & 1) == 1)
            {
                // write(1, "1", 1);
                kill(pid, SIGUSR1); // -> 1
            }
            else
            {
                // write(1, "0", 1);
                kill(pid, SIGUSR2); // -> 0
            }
            bits--;
            usleep(80);
        }
        usleep(80);
        bits = 7;
        i++;
    }
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("ERROR! The client takes two parameters:\n", 1);
		ft_putstr_fd("./client <PID> <STRING>", 1);
	}
	else
		send_bits(argv[2], ft_atoi(argv[1]));
	return (0);
}

// TODO: 
// *hace falta comprovar todo
// *que el mensaje no este vacio

//encoder
//por cada str[i]
//codifica por cada letra unos bits y los va devolviendo
//con kill() de la señal

//bits -> (character >> bits & 1) == 1
//pasa el character a bits y en caso de ser 1
//, devuelve true (que es uno) y kill(pid, SIGUSR1)

// kill(pid, SIGUSR1); // -> 1
// kill(pid, SIGUSR2); // -> 0