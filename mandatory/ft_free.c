/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaoud <msaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:02:53 by msaoud            #+#    #+#             */
/*   Updated: 2022/02/17 05:55:53 by msaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_free(t_game *game, int v)
{
	int	i;

	i = -1;
	while (game->map[++i])
	{
		if (game->map[i])
		{
			free(game->map[i]);
			game->map[i] = NULL;
		}
	}
	free(game->map);
	game->map = NULL;
	if (v == 1)
		write(1, "game over : you lose !!!", 25);
	else if (v == 2)
		write(1, "game over : you win !!!", 24);
}

int	ft_exit(int bouton, t_game *game)
{
	(void)bouton;
	(void)game;
	exit (0);
	return (1);
}
