/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_utils_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:16:47 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 20:07:56 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

unsigned char	*ft_strappnd(unsigned char *s1, unsigned char c)
{
	size_t			i;
	size_t			s1_len;
	unsigned char	*s;
	int				c_len;

	c_len = (c != '\0');
	if (!s1)
		s1_len = 0;
	else
		s1_len = ft_strlen((const char *)s1);
	s = (unsigned char *)malloc((s1_len + c_len + 1) * sizeof(unsigned char));
	if (!s)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		s[i] = s1[i];
		i++;
	}
	s[i++] = c;
	if (c_len)
		s[i] = '\0';
	return (s);
}

int	ft_atoi(char *nptr)
{
	unsigned int	res;
	int				sign;

	sign = 1;
	res = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while ((*nptr >= 48 && *nptr <= 57) && *nptr)
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (res * sign);
}

static int	ft_isvalid(char *base)
{
	int	i;
	int	j;
	int	base_len;

	base_len = ft_strlen(base);
	i = 0;
	if (base[0] == '\0' || base_len == 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] <= 32 || base[i] == 127 || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_getint(int n, unsigned char *str, char *base)
{
	int	d;
	int	q;
	int	i;
	int	r;
	int	stop;

	stop = 1;
	d = ft_strlen(base);
	i = 0;
	while (i <= d - 1)
	{
		if (*str == *(base + i))
		{
			stop = 0;
			r = i;
		}
		i++;
	}
	if (*str == '\0' || stop)
		return (n);
	q = n;
	n = (d * q) + r;
	return (ft_getint(n, str + 1, base));
}

int	ft_atoi_base(unsigned char *str, char *base)
{
	int	i;
	int	result;
	int	sign;
	int	nminus;

	result = 0;
	nminus = 0;
	if (ft_isvalid(base) == 1)
	{
		i = 0;
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				nminus++;
			i++;
		}
		sign = 1;
		if (nminus % 2)
			sign = -1;
		result = ft_getint(0, str + i, base);
		return (result * sign);
	}
	return (0);
}
