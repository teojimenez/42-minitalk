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

// static int	ft_len_int(int nb)
// {
// 	int	i;

// 	i = 0;
// 	if (nb == 0)
// 		return (1);
// 	if (nb < 0)
// 	{
// 		nb = -nb;
// 		i++;
// 	}
// 	while (nb > 0)
// 	{
// 		nb /= 10;
// 		i++;
// 	}
// 	return (i);
// }

// static char	*extra(int nb, char *str, int len)
// {
// 	int	digit;
// 	int	i;

// 	i = 0;
// 	if (nb < 0)
// 	{
// 		nb = -nb;
// 		str[0] = '-';
// 		i++;
// 	}
// 	while (len > i)
// 	{
// 		digit = nb % 10;
// 		str[--len] = digit + '0';
// 		nb /= 10;
// 	}
// 	return (str);
// }

// char	*ft_itoa(int nb)
// {
// 	char	*str;
// 	int		len;

// 	len = ft_len_int(nb);
// 	if (nb <= -2147483648)
// 		return (ft_strdup("-2147483648"));
// 	else if (nb >= 2147483647)
// 		return (ft_strdup("2147483647"));
// 	str = ft_calloc(len + 1, sizeof(char));
// 	if (!str)
// 		return (0);
// 	str = extra(nb, str, len);
// 	return (str);
// }

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	memory = (void *)malloc(count * size);
	if (!memory)
		return (0);
	ft_bzero(memory, count * size);
	return (memory);
}

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*c;

	i = 0;
	c = (char *)str;
	while (i < n)
		c[i++] = '\0';
}

// char	*ft_strdup(char *s1)
// {
// 	char	*memory;
// 	int		i;

// 	i = -1;
// 	memory = (char *)malloc(ft_strlen(s1) + 1);
// 	if (!memory)
// 		return (NULL);
// 	while (s1[++i])
// 		memory[i] = s1[i];
// 	memory[i] = '\0';
// 	return (memory);
// }