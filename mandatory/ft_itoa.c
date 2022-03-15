/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaoud <msaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 00:35:25 by msaoud            #+#    #+#             */
/*   Updated: 2022/02/17 01:10:02 by msaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	ft_count(long n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_itoanega(int n)
{
	char	*str;
	int		j;
	long	nb;

	nb = n;
	nb = nb * -1;
	j = ft_count(nb);
	str = malloc(j + 2);
	if (!str)
		return (NULL);
	str[j + 1] = '\0';
	while (j > 0)
	{
		str[j] = (nb % 10) + '0';
		nb = nb / 10;
		j--;
	}
	str[j] = '-';
	return (str);
}

static char	*ft_itoaposs(int n)
{
	char	*str;
	int		j;

	j = ft_count(n);
	str = malloc(j + 1);
	if (!str)
		return (NULL);
	str[j--] = '\0';
	while (j >= 0)
	{
		str[j] = (n % 10) + '0';
		n = n / 10;
		j--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;

	nb = n;
	if (nb == 0)
	{
		str = malloc(2);
		str[0] = '0';
		str[1] = '\0';
	}
	else if (nb > 0)
		str = ft_itoaposs(nb);
	else
		str = ft_itoanega(nb);
	return (str);
}
