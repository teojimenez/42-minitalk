/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:11:28 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/11 13:11:28 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_num(char *str)
{
	char	*regex;
	int		i;

	i = 0;
	regex = "-0123456789";
	while (*str)
	{
		i = 0;
		while (regex[i] != '\0')
		{
			if (regex[i] == *str)
				break ;
			i++;
		}
		if (regex[i] == '\0' && regex[i - 1] != *str)
			return (-1);
		str++;
	}
	return (0);
}

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

char	*ft_strdup(char *s1)
{
	int		i;
	char	*aux;

	aux = (char *) malloc(ft_strlen(s1) + 1);
	if (!aux)
		return (NULL);
	i = -1;
	while (s1[++i])
		aux[i] = s1[i];
	aux[i] = '\0';
	return (aux);
}

static size_t	len_number(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	else if (nb <= -2147483648)
		return (11);
	else if (nb > -2147483648 && nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*convert_int_to_string(int n)
{
	char			*digits;
	unsigned int	i;
	size_t			len_nb;
	int				digit;

	len_nb = len_number(n);
	digits = (char *)malloc(len_nb + 1);
	if (!digits)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		n = -n;
		digits[i++] = '-';
	}
	while (n > 0)
	{
		digit = n % 10;
		digits[--len_nb] = digit + '0';
		n = n / 10;
		i++;
	}
	digits[i] = '\0';
	return (digits);
}

char	*ft_itoa(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	else if (n < -2147483647)
		return (ft_strdup("-2147483648"));
	else if (n > 2147483647)
		return (ft_strdup("2147483647"));
	return (convert_int_to_string(n));
}