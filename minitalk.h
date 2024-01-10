/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:50:11 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/10 15:50:11 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "minitalk.h"
# include <stdlib.h> //malloc
# include <unistd.h>
# include <signal.h>
	
void	ft_putstr_fd(char *s, int fd);
int	    ft_atoi(const char *str);
void	ft_putnbr_fd(int nb, int fd);

#endif