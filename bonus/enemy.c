/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaoud <msaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:03:07 by msaoud            #+#    #+#             */
/*   Updated: 2022/02/18 04:04:33 by msaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

//enemy postion
void	ft_enemyposition(t_game *game)
{
	game->ni = -1;
	game->nj = -1;
	while (++game->ni < game->width)
	{
		game->nj = -1;
		while (++game->nj < game->height)
		{
			if (game->map[game->ni][game->nj] == 'N')
				return ;
		}
	}
}

void	ft_rightenemy(t_game *game)
{
	if (game->map[game->ni][game->nj + 1] == '0')
	{
		game->map[game->ni][game->nj + 1] = 'N';
		game->map[game->ni][game->nj] = '0';
		game->nj++;
	}
}

void	ft_upenemy(t_game *game)
{
	if (game->map[game->ni - 1][game->nj] == '0')
	{
		game->map[game->ni - 1][game->nj] = 'N';
		game->map[game->ni][game->nj] = '0';
		game->ni--;
	}	
}

void	ft_downenemy(t_game *game)
{
	if (game->map[game->ni + 1][game->nj] == '0')
	{
		game->map[game->ni + 1][game->nj] = 'N';
		game->map[game->ni][game->nj] = '0';
		game->ni++;
	}
}

void	ft_leftenemy(t_game *game)
{
	if (game->map[game->ni][game->nj - 1] == '0')
	{
		ft_enemyposition(game);
		game->map[game->ni][game->nj - 1] = 'N';
		game->map[game->ni][game->nj] = '0';
		game->nj--;
	}
}
