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
//pasa el character a bits y en caso de ser 1, devulve true (que es uno) y kill(pid, SIGUSR1)

int main(void)
{
    return (0);
}