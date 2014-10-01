/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gof.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/01 03:10:37 by jchichep          #+#    #+#             */
/*   Updated: 2014/10/01 07:11:29 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOF_H
# define GOF_H

# define TURN_TIME 50000
# define SIZE_X 50
# define SIZE_Y 250

int			ft_strlen(char *str);
void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_atoi(char *str);
void		clear_map(char map[SIZE_X][SIZE_Y]);
void		show_map(char map[SIZE_X][SIZE_Y]);
void		algo(char before[SIZE_X][SIZE_Y], char after[SIZE_X][SIZE_Y], int turn);

#endif
