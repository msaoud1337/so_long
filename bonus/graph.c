/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaoud <msaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 03:15:43 by msaoud            #+#    #+#             */
/*   Updated: 2022/02/17 23:08:11 by msaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

// hundling the bouton esc
int	ft_hundlingkey(int bouton, t_game *game)
{
	if (bouton == 53)
	{
		ft_free(game, 0);
		exit (0);
	}
	if (bouton == 13)
		ft_up(game);
	if (bouton == 1)
		ft_down(game);
	if (bouton == 0)
		ft_left(game);
	if (bouton == 2)
		ft_right(game);
	ft_enemymouvement(game);
	mlx_clear_window(game->mlx, game->window);
	ft_images(game);
	return (1);
}

void	ft_pl(t_game *game)
{
	if (game->map[game->i][game->j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->xpmexit, game->x, game->y);
	else if (game->map[game->i][game->j] == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->xpmplayer, game->x, game->y);
	else if (game->map[game->i][game->j] == 'N')
		ft_enemyanimation(game);
}

//puting image to window
void	ft_images(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->i = -1;
	while (++game->i < game->width)
	{
		game->j = -1;
		while (++game->j < game->height)
		{
			if (game->map[game->i][game->j] == '1')
				mlx_put_image_to_window(game->mlx, game->window,
					game->xpmwall, game->x, game->y);
			else if (game->map[game->i][game->j] == '0')
				mlx_put_image_to_window(game->mlx, game->window,
					game->xpmempty, game->x, game->y);
			else if (game->map[game->i][game->j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->xpmcollectable, game->x, game->y);
			ft_pl(game);
			game->x += 100;
		}
		mlx_string_put(game->mlx, game->window, 50, 50,
			0xFFFFFF, ft_itoa(game->nmoves));
		game->x = 0;
		game->y += 100;
	}
}

// collecting the xpm files
void	ft_collectingxpm(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->xpmwall = mlx_xpm_file_to_image(game->mlx, "./xpm/1.xpm", &i, &j);
	game->xpmenemy = mlx_xpm_file_to_image(game->mlx, "./xpm/6.xpm", &i, &j);
	game->xpmcollectable = mlx_xpm_file_to_image(game->mlx,
			"./xpm/7.xpm", &i, &j);
	game->xpmplayer = mlx_xpm_file_to_image(game->mlx, "./xpm/3.xpm", &i, &j);
	game->xpmexit = mlx_xpm_file_to_image(game->mlx, "./xpm/2.xpm", &i, &j);
	game->xpmempty = mlx_xpm_file_to_image(game->mlx, "./xpm/4.xpm", &i, &j);
	game->xpmenemy1 = mlx_xpm_file_to_image(game->mlx, "./xpm/10..xpm", &i, &j);
	game->xpmenemy2 = mlx_xpm_file_to_image(game->mlx, "./xpm/11.xpm", &i, &j);
	game->xpmenemy3 = mlx_xpm_file_to_image(game->mlx, "./xpm/12.xpm", &i, &j);
	game->xpmenemy4 = mlx_xpm_file_to_image(game->mlx, "./xpm/13..xpm", &i, &j);
	game->xpmenemy5 = mlx_xpm_file_to_image(game->mlx, "./xpm/14.xpm", &i, &j);
}

// init the graph
void	ft_graph(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->height * 100,
			game->width * 100, "so_long");
	ft_collectingxpm(game);
	ft_images(game);
	ft_playerposition(game);
	ft_enemyposition(game);
	mlx_key_hook(game->window, ft_hundlingkey, game);
	mlx_hook(game->window, 17, 0, ft_exit, game);
	mlx_loop(game->mlx);
}
