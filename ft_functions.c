/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/01 03:09:43 by jchichep          #+#    #+#             */
/*   Updated: 2014/10/01 03:49:47 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_atoi(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		i = i * 10 + (*str - 48);
		++str;
	}
	return (i);
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
