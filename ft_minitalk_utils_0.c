/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_utils_0.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 02:14:29 by amenses-          #+#    #+#             */
/*   Updated: 2022/12/11 01:03:39 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_error(char *err_msg)
{
	ft_printf("%s", err_msg);
	exit(EXIT_FAILURE);
}

char	*ft_itoa_bin(unsigned long long n)
{
	int			len;
	char		*s;

	len = 8;
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (len > 0)
	{
		s[len - 1] = (n % 2) + '0';
		n /= 2;
		len--;
	}
	return (s);
}

void	ft_sendchr(pid_t pid, char c)
{
	int		i;
	int		sig;
	char	*bin;

	bin = ft_itoa_bin(c);
	i = 0;
	while (i < 8)
	{
		sig = SIGUSR2;
		if (bin[i] == '1')
			sig = SIGUSR1;
		usleep(200);
		if (kill(pid, sig) == -1)
		{
			free(bin);
			ft_error("Error: failed to send message to server\n");
		}
		i++;
	}
	free(bin);
}

void	ft_sendmsg(pid_t pid, char *msg)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(msg))
	{
		ft_sendchr(pid, msg[i]);
		i++;
	}
}

unsigned char	*ft_strdup_null(unsigned char *s)
{
	size_t			len;
	unsigned char	*dup;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	dup = malloc((len + 1) * sizeof(unsigned char));
	if (!dup)
		return (NULL);
	len = 0;
	while (s[len])
	{
		dup[len] = s[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}
