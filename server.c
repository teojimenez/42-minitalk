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

// static char	*g_result = NULL;

// void	receive_bits(int bit)
// {
// 	static int	i = 0;
// 	static int	j = 0;
// 	static int	flag = 1;
// 	static char	whole_c = 0;
// 	static int	int_nb;
// 	static char *g_result = NULL;

// 	if (flag == 1)
// 	{
// 		add_bits(bit, &whole_c, &int_nb, 0);
// 		if (++i == 32)
// 			if (add_memory(&i, &flag, &int_nb, &g_result) == -1)
// 				return ;
// 	}
// 	else
// 	{
// 		add_bits(bit, &whole_c, &int_nb, 1);
// 		if (++i == 8)
// 			add_content(&i, &j, &g_result, &whole_c);
// 		if (j == int_nb)
// 		{
// 			flag = reset(&int_nb, &i, &j, &g_result);
// 			free(g_result);
// 			whole_c = 0;
// 		}
// 	}
// }

#include <stdio.h>

void    receive_bits(int bit)
{
    static int i = 0;
    static int j = 0;
    static int flag = 1;
    static char whole_c = 0;
    static int int_nb;
    static char *result = NULL;
    // printf("%d", flag);
    if (flag == 1) 
    {
        if (bit == SIGUSR1) {  // Cambia 1 por el valor de tu bit
            int_nb = (int_nb << 1) | 1;
        } else if (bit == SIGUSR2)
        {  // Cambia 0 por el valor de tu otro bit
            int_nb = int_nb << 1;
        }
        // printf("%d", i);
        i++;
        if (i == 32) {  // Cambia 32 por el número de bits que deseas en tu entero
            i = 0;
            flag = 0;
            // printf("%d", int_nb);
            result = (char *)malloc(int_nb + 1 * sizeof(char));
            if(!result)
                return ;
        }
    }
    else
    {
        // nb = atoi(&char_nb);
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
        if(j == int_nb)
        {
            result[j] = '\0';
            ft_putstr_fd(result, 1);
            printf("NB:%d\n", int_nb);
            result[0] = '\0';
            free(result);
            // int_nb = 0;
            int_nb = 0;
            i = 0;
            flag = 1;
            whole_c = 0;
            j = 0;
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