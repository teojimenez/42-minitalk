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
    static int j = 0;
    static int flag = 1;
    static char whole_c = 0;
    static char char_nb;
    char static *result = NULL;
    int nb = 0;

    // printf("OUTSIDE FLAG\n");
    if (flag == 1)
    {
        // printf("INSIDE FLAG\n");
        if (bit == SIGUSR1) 
        {
            // printf("1");
            char_nb = (char_nb << 1) | 1;
        }
        else if (bit == SIGUSR2) 
        {
            // printf("0");
            char_nb = char_nb << 1;
        }

        i++;
        if (i == 8)
        {
            nb = atoi(&char_nb);
            i = 0;
            flag = 0;
            result = (char *)malloc(nb + 1 * sizeof(char));
        }
        // printf("VALOR i=%d\n", i);
    }
    else
    {
        nb = atoi(&char_nb);
        // printf("NUMBER\n");
        if (bit == SIGUSR1) 
            whole_c = (whole_c << 1) | 1;
        else if (bit == SIGUSR2)
            whole_c = whole_c << 1;
        i++;
        if (i == 8)
        {
            // printf("NEW CHAR\n");
            i = 0;
            // ft_putchar_fd(whole_c, 1);
            result[j] = whole_c;
            j++;
            whole_c = 0;
        }
        // printf("J:%d\n", j);
        // printf("NB:%d\n", nb);
        if(j == nb)
        {
            result[j] = '\0';
            ft_putstr_fd(result, 1);
            // free(result);
            result[0] = '\0';
            char_nb = 0;
            i = 0;
            flag = 1;
            whole_c = 0;
            char_nb = 0;
            j = 0;
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