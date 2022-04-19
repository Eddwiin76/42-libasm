/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:00:51 by tpierre           #+#    #+#             */
/*   Updated: 2020/10/23 11:43:29 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBASM_H
#	define LIBASM_H

#	include <stdlib.h>
#	include <stdio.h>
#	include <errno.h>

size_t		ft_strlen(const char *str);
char		*ft_strcpy(char *dest, char *src);
int			ft_strcmp(const char *s1, const char *s2);
__ssize_t	ft_write(int fd, const void *buf, size_t count);
__ssize_t	ft_read(int fd, void *buf, size_t count);
char		*ft_strdup(const char *s);

#	endif
