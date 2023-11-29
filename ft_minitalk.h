/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 02:15:01 by amenses-          #+#    #+#             */
/*   Updated: 2022/12/11 00:47:03 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

void			ft_error(char *err_msg);
char			*ft_itoa_bin(unsigned long long n);
void			ft_sendchr(pid_t pid, char c);
void			ft_sendmsg(pid_t pid, char *msg);
unsigned char	*ft_strdup_null(unsigned char *s);

unsigned char	*ft_strappnd(unsigned char *s1, unsigned char c);
int				ft_atoi(char *nptr);
int				ft_atoi_base(unsigned char *str, char *base);

#endif