/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaoud <msaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:13:15 by msaoud            #+#    #+#             */
/*   Updated: 2022/02/18 04:02:31 by msaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_BONUS_H
# define GAME_BONUS_H

# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"
# include <mlx.h>
# include <unistd.h>

typedef struct s_game
{
	char	**map;

	char	*collxpm;
	char	*playxpm;
	char	*wallxpm;
	char	*emptyxpm;
	int		width;
	int		height;
	int		gameline;

	int		player;
	int		exit;
	int		collectable;
	int		enemy;
	int		others;

	void	*mlx;
	void	*window;
	void	*image;

	int		a;
	int		b;

	int		i;
	int		j;

	int		x;
	int		y;
	int		nmoves;

	int		z;
	int		w;

	int		ni;
	int		nj;
	void	*xpmwall;
	void	*xpmenemy;
	void	*xpmenemy1;
	void	*xpmenemy2;
	void	*xpmenemy3;
	void	*xpmenemy4;
	void	*xpmenemy5;
	void	*xpmenemy6;

	void	*xpmcollectable;
	void	*xpmplayer;
	void	*xpmexit;
	void	*xpmempty;

}	t_game;

int		ft_checkfilename(char *str, char *s);
int		ft_checkingcontent(t_game *game);
void	ft_readingthecontent(t_game *game);
int		ft_wallrightleft(char *str);
int		ft_wallupdown(char *str);
int		ft_checkingthewall(t_game *game);
int		ft_checkthemap(t_game *game);
int		ft_countmapline(char *file);
int		ft_readmap(t_game *game, char *file);
void	ft_initvarriable(t_game *game);
void	ft_graph(t_game *game);
void	ft_collectingxpm(t_game *game);
void	ft_images(t_game *game);
int		ft_hundlingkey(int bouton, t_game *game);
int		ft_playerposition(t_game *game);
void	ft_up(t_game *game);
void	ft_down(t_game *game);
void	ft_left(t_game *game);
void	ft_right(t_game *game);
void	ft_putnbr(int nbr);
void	ft_putchar(char c);
void	t_pl(t_game *game);
void	ft_putstr(char	*str);
void	ft_enemyanimation(t_game *game);
char	*ft_itoa(int n);
void	ft_free(t_game *game, int v);
int		ft_exit(int bouton, t_game *game);
void	ft_enemymouvement(t_game *game);
void	ft_leftenemy(t_game *game);
void	ft_rightenemy(t_game *game);
void	ft_enemyposition(t_game *game);
void	ft_downenemy(t_game *name);
void	ft_upenemy(t_game *game);

#endif