/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:24:47 by amenses-          #+#    #+#             */
/*   Updated: 2022/12/11 01:07:21 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_handle(int sig)
{
	(void) sig;
	ft_printf("Copy that!\n");
}

int	main(int argc, char **argv)
{
	pid_t					pid;
	char					*msg;
	struct sigaction		sa;

	if (argc != 3)
		exit(EXIT_FAILURE);
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	sa.sa_handler = &ft_handle;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error("Error: failed to define signal action\n");
	ft_sendmsg(pid, msg);
	pause();
	return (0);
}
