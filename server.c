/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:22:28 by amenses-          #+#    #+#             */
/*   Updated: 2022/12/11 01:04:24 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

unsigned char		*g_msg;

unsigned char	ft_getbit(int sig)
{
	unsigned char	b;

	b = '1';
	if (sig == SIGUSR2)
		b = '0';
	return (b);
}

void	ft_handle(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char		b_chr[9];
	unsigned char				c;
	static int					i;
	unsigned char				*tmp;

	(void) info;
	(void) ucontext;
	tmp = NULL;
	c = 'a';
	b_chr[i++] = ft_getbit(sig);
	b_chr[i] = '\0';
	if (i == 8)
	{
		c = ft_atoi_base(b_chr, "01");
		tmp = ft_strdup_null(g_msg);
		g_msg = ft_strappnd(tmp, c);
		free(tmp);
		i = 0;
	}
	if (g_msg && c == '\0')
	{
		ft_printf("%s\n", g_msg);
		free(g_msg);
		g_msg = NULL;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa1;
	struct sigaction	sa2;
	int					pid;

	(void) argc;
	(void) argv;
	pid = getpid();
	ft_printf("PID=%d\n", pid);
	sa1.sa_sigaction = &ft_handle;
	sa1.sa_flags = SA_SIGINFO;
	sigemptyset(&sa1.sa_mask);
	sigaddset(&sa1.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa1, NULL) == -1)
		ft_error("Error: failed to define signal action\n");
	sa2.sa_sigaction = &ft_handle;
	sa2.sa_flags = SA_SIGINFO;
	sigemptyset(&sa2.sa_mask);
	sigaddset(&sa2.sa_mask, SIGUSR1);
	if (sigaction(SIGUSR2, &sa2, NULL) == -1)
		ft_error("Error: failed to define signal action\n");
	while (1)
		pause();
	return (0);
}
