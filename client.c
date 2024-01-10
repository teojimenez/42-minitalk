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

//encoder
//por cada str[i]
//codifica por cada letra unos bits y los va devolviendo
//con kill() de la señal

//bits -> (character >> bits & 1) == 1
//pasa el character a bits y en caso de ser 1, devuelve true (que es uno) y kill(pid, SIGUSR1)

void    send_bits(char *str, int pid)
{
    int i = 0;
    int bits = 8;

    while(str[i] != '\0')
    {
        while(bits <= 7)
        {
            if((str[i] >> bits & 1) == 1)
                kill(pid, SIGUSR1); // -> 1
            else
                kill(pid, SIGUSR2); // -> 2
            bits--;
        }
        usleep(80);
        bits = 8;
        i++;
    }
}

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        ft_putstr_fd("ERROR! The client takes two parameters:", 1);
        ft_putstr_fd("./client <PID> <STRING>\n", 1);
    }
    else
    {
        send_bits(argv[2], ft_atoi(argv[1]));
    }
    return (0);
}