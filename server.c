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

//decoder *(va letra por letra y hasta que no es i = 8 no ha acabado la letra)
//int i 
//int c

void    receive_bits(int bit)
{
    static int i = 0;
    static char whole_c;
    // int val;
    while(i < 8)
    {
        if(i <= 8)
        {
            if (bit == 1)
                whole_c = (bit <<  1) | 1;
            else
                whole_c <= 1;
            i++;
            break;
        }else
        {
            i = 0;
            ft_putstr_fd(whole_c, 1);
        }
    }

}

int main(void)
{
    //se queda escuchando signal() con las dos funciones
    //bucle infinito
    ft_putstr_fd("\nPID: [", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putstr_fd("]", 1);
    ft_putstr_fd("\nWaiting for a signal ...\n", 1);
    signal(SIGUSR1, receive_bits); //-> 1
    signal(SIGUSR2, receive_bits);// -> 0
    while(1)
        ;
    return (0);
}
