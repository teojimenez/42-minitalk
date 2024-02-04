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
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_strlen(char *str);

// SERVER EXTRA FUNCTIONS

int		reset(int *int_nb, int *i, int *j, char **result);
void	add_content(int *i, int *j, char **result, char *whole_c);
int		add_memory(int *i, int *flag, int *int_nb, char **result);
void	add_bits(int bit, char *whole_c, int *int_nb, int flag_chosen);
int		is_num(char *str);

# define C_GREEN	"\x1b[32m"
# define C_RESET	"\x1b[0m"
# define C_RED		"\x1b[31m"

#endif
