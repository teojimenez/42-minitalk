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
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int nb);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *str, size_t n);
char	*ft_strdup(char *s1);
int     ft_strlen(char *str);

# define C_GREEN	"\x1b[32m"
# define C_RESET	"\x1b[0m"
#endif