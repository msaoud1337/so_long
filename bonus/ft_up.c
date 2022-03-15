/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaoud <msaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 05:34:57 by msaoud            #+#    #+#             */
/*   Updated: 2022/02/17 06:06:09 by msaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	ft_right(t_game *game)
{
	if (game->map[game->z][game->w + 1] == '0')
	{
		game->map[game->z][game->w + 1] = 'P';
		game->map[game->z][game->w] = '0';
		game->w++;
		game->nmoves++;
	}
	else if (game->map[game->z][game->w + 1] == 'C')
	{
		game->map[game->z][game->w + 1] = 'P';
		game->map[game->z][game->w] = '0';
		game->w++;
		game->collectable--;
		game->nmoves++;
	}
	else if (game->map[game->z][game->w + 1] == 'E' && !game->collectable)
	{
		ft_free(game, 2);
		exit (0);
	}
	else if (game->map[game->z][game->w + 1] == 'N')
	{
		ft_free(game, 1);
		exit (0);
	}
}

void	ft_left(t_game *game)
{
	if (game->map[game->z][game->w - 1] == '0')
	{
		game->map[game->z][game->w - 1] = 'P';
		game->map[game->z][game->w] = '0';
		game->w--;
		game->nmoves++;
	}
	else if (game->map[game->z][game->w - 1] == 'C')
	{
		game->map[game->z][game->w - 1] = 'P';
		game->map[game->z][game->w] = '0';
		game->w--;
		game->collectable--;
		game->nmoves++;
	}
	else if (game->map[game->z][game->w - 1] == 'E' && !game->collectable)
	{
		ft_free(game, 2);
		exit (0);
	}
	else if (game->map[game->z][game->w - 1] == 'N')
	{
		ft_free(game, 1);
		exit (0);
	}
}

void	ft_down(t_game *game)
{
	if (game->map[game->z + 1][game->w] == '0')
	{
		game->map[game->z + 1][game->w] = 'P';
		game->map[game->z][game->w] = '0';
		game->z++;
		game->nmoves++;
	}
	else if (game->map[game->z + 1][game->w] == 'C')
	{
		game->map[game->z + 1][game->w] = 'P';
		game->map[game->z][game->w] = '0';
		game->z++;
		game->nmoves++;
		game->collectable--;
	}
	else if (game->map[game->z + 1][game->w] == 'E' && !game->collectable)
	{
		ft_free(game, 2);
		exit (0);
	}
	else if (game->map[game->z + 1][game->w] == 'N')
	{
		ft_free(game, 1);
		exit (0);
	}
}

void	ft_up(t_game *game)
{
	if (game->map[game->z - 1][game->w] == '0')
	{
		game->map[game->z - 1][game->w] = 'P';
		game->map[game->z][game->w] = '0';
		game->z--;
		game->nmoves++;
	}
	else if (game->map[game->z - 1][game->w] == 'C')
	{
		game->map[game->z - 1][game->w] = 'P';
		game->map[game->z][game->w] = '0';
		game->z--;
		game->nmoves++;
		game->collectable--;
	}
	else if (game->map[game->z -1][game->w] == 'E' && game->collectable == 0)
	{
		ft_free(game, 2);
		exit (0);
	}
	else if (game->map[game->z -1][game->w] == 'N')
	{
		ft_free(game, 1);
		exit (0);
	}
}
