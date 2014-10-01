/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/01 03:51:56 by jchichep          #+#    #+#             */
/*   Updated: 2014/10/01 07:03:46 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "gol.h"

int		check_around(char map[SIZE_X][SIZE_Y], int i, int j)
{
	int	result;

	result = 0;
	if (i - 1 >= 0 && j - 1 >= 0 && map[i - 1][j - 1] == 1)
		++result;
	if (i - 1 >= 0 && map[i - 1][j] == 1)
		++result;
	if (i - 1 >= 0 && j + 1 < SIZE_Y && map[i - 1][j + 1] == 1)
		++result;
	if (j - 1 >= 0 && map[i][j - 1] == 1)
		++result;
	if (j + 1 < SIZE_Y && map[i][j + 1] == 1)
		++result;
	if (i + 1 < SIZE_X && j - 1 >= 0 && map[i + 1][j - 1] == 1)
		++result;
	if (i + 1 < SIZE_X && map[i + 1][j] == 1)
		++result;
	if (i + 1 < SIZE_X && j + 1 < SIZE_Y && map[i + 1][j + 1] == 1)
		++result;
	return (result);
}

void		copy_map(char after[SIZE_X][SIZE_Y], char before[SIZE_X][SIZE_Y])
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < SIZE_X)
	{
		while (++j < SIZE_Y)
			before[i][j] = after[i][j];
		j = -1;
	}
}

void	algo(char before[SIZE_X][SIZE_Y], char after[SIZE_X][SIZE_Y], int turn)
{
	int	i;
	int j;

	i = -1;
	j = -1;
	if (turn == 0)
		turn = -1;
	while (turn != 0)
	{
		while (++i < SIZE_X)
		{
			while (++j < SIZE_Y)
			{
				if (check_around(before, i, j) == 3)
					after[i][j] = 1;
				else if (check_around(before, i, j) == 2 && before[i][j] == 1)
					after[i][j] = 1;
				else
					after[i][j] = 0;
			}
			j = -1;
		}
		i = -1;
		copy_map(after, before);
		clear_map(after);
		ft_putstr("\033[H\033[2J");
		show_map(before);
		usleep(TURN_TIME);
		if (turn != -1)
			--turn;
	}
}
