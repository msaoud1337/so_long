/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaoud <msaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 04:57:58 by msaoud            #+#    #+#             */
/*   Updated: 2022/02/18 22:09:17 by msaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

//init variable
void	ft_initvarriable(t_game *game)
{
	game->a = -1;
	game->b = -1;
	game->player = 0;
	game->collectable = 0;
	game->exit = 0;
	game->others = 0;
	game->enemy = 0;
	game->j = -1;
	game->i = -1;
	game->x = 0;
	game->y = 0;
	game->z = -1;
	game->w = -1;
	game->nmoves = 0;
}

// player position
int	ft_playerposition(t_game *game)
{
	while (++game->z < game->width)
	{
		game->w = -1;
		while (++game->w < game->height)
		{
			if (game->map[game->z][game->w] == 'P')
				return (1);
		}
	}
	return (1);
}

//enemy animation
void	ft_enemyanimation(t_game *game)
{
	static int	i;

	i++;
	if (i == 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->xpmenemy, game->x, game->y);
	else if (i == 2)
		mlx_put_image_to_window(game->mlx, game->window,
			game->xpmenemy1, game->x, game->y);
	else if (i == 3)
		mlx_put_image_to_window(game->mlx, game->window,
			game->xpmenemy2, game->x, game->y);
	else if (i == 4)
		mlx_put_image_to_window(game->mlx, game->window,
			game->xpmenemy3, game->x, game->y);
	else if (i == 5)
		mlx_put_image_to_window(game->mlx, game->window,
			game->xpmenemy4, game->x, game->y);
	else
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->xpmenemy, game->x, game->y);
		i = 0;
	}
}

int	main(int arc, char **arv)
{
	t_game	game;

	if (arc != 2)
	{
		ft_putstr("check the argument number !!");
		return (1);
	}
	if (!ft_readmap(&game, arv[1]) || !ft_checkfilename(arv[1], ".ber"))
	{
		ft_putstr("error\nmap invalid !!!!");
		return (1);
	}
	ft_readingthecontent(&game);
	if (!ft_checkthemap(&game)
		|| !ft_checkingthewall(&game) || !ft_checkingcontent(&game))
	{
		ft_free(&game, 0);
		ft_putstr("error\nmap invalid !!!!");
		return (1);
	}
	ft_graph(&game);
	return (0);
}
