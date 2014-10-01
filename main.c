/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/01 02:49:20 by jchichep          #+#    #+#             */
/*   Updated: 2014/10/01 07:10:49 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "gol.h"

void		show_map(char map[SIZE_X][SIZE_Y])
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	ft_putchar('.');
	while (++j < SIZE_Y)
		ft_putchar('_');
	ft_putstr(".\n");
	while (++i < SIZE_X)
	{
		j = -1;
		ft_putchar('|');
		while (++j <SIZE_Y)
		{
			if (map[i][j] == 0)
				ft_putchar(' ');
			else
				ft_putstr("\033[47m \033[0m");
		}
		ft_putstr("|\n");
	}
	j = -1;
	ft_putchar('\'');
	while (++j < SIZE_Y)
		ft_putchar('-');
	ft_putstr("\'\n");
}

void		init_map(char map[SIZE_X][SIZE_Y], int cell)
{
	int		x;
	int		y;

	srand(time(NULL));
	while (cell > 0)
	{
		x = rand() % SIZE_X;
		y = rand() % SIZE_Y;
		if (map[x][y] == 0)
		{
			--cell;
			map[x][y] = 1;
		}
	}
}

void		clear_map(char map[SIZE_X][SIZE_Y])
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < SIZE_X)
	{
		while (++j < SIZE_Y)
			map[i][j] = 0;
		j = -1;
	}
}

int			main(int ac, char **av)
{
	char	before[SIZE_X][SIZE_Y];
	char	after[SIZE_X][SIZE_Y];

	(void)ac;
	clear_map(before);
	clear_map(after);
	init_map(before, ft_atoi(av[1]));
	show_map(before);
	usleep(TURN_TIME);
	algo(before, after, ft_atoi(av[2]));
	return (0);
}
