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


//whole_c = (whole_c << 1) | bit; 
//cada bit se mueve a la izq y el mas izq sera 0. 
//"| bit " -> si el bit es 1, el mas a la derecha se establecera en 1
#include <stdio.h>

void    receive_bits(int bit)
{
    static int i = 0;
    static char whole_c;

     if (bit == SIGUSR1) 
        whole_c = (whole_c << 1) | 1;
    else if (bit == SIGUSR2) 
        whole_c = whole_c << 1;
    i++;
    if (i == 8)
    {
        i = 0;
        ft_putchar_fd(whole_c, 1);
        whole_c = 0;
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
        pause();
    return (0);
}


    //si el bit es un 1
    //hace una operacion desplaza a la izq de whole_a
    //operador OR con valor 1; resultado: conjunto de bits de la operacion
    //de desplazo a la izq con el ultimo bit en 1; (desplazo: para que haya espacio para el ultimo)
    //  if (bit == SIGUSR1) 
    //     whole_c = (whole_c << 1) | 1; //OR: 0 | 1 = 1

    //si el bit es 0
    // <== operador de asignacion a la izquierda
    // el valor de whole_a lo desplaza a la izquierda por y posiciones (whole_c <== "1")
    // RESUMEN: desplaza todos los bits en el valor almacenado en whole_c una posición a la izquierda.
    //(entonces los 0 del otro lado pasan al otro lado y por eso se pone un 0)
    // else if (bit == SIGUSR2) 
    //     whole_c = whole_c << 1; //x = x << y ->mismo que: x <== y;