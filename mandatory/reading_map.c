/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaoud <msaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 04:56:07 by msaoud            #+#    #+#             */
/*   Updated: 2022/02/17 06:16:39 by msaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// reading the map content
void	ft_readingthecontent(t_game *game)
{
	ft_initvarriable(game);
	while (game->map[++game->a])
	{
		game->b = -1;
		while (game->map[game->a][++game->b])
		{
			if (game->map[game->a][game->b] == 'P')
				game->player++;
			if (game->map[game->a][game->b] == 'E')
				game->exit++;
			if (game->map[game->a][game->b] == 'C')
				game->collectable++;
			else if (game->map[game->a][game->b] != 'C'
				&& game->map[game->a][game->b] != 'E'
				&& game->map[game->a][game->b] != 'P'
				&& game->map[game->a][game->b] != '1'
				&& game->map[game->a][game->b] != '0'
				&& game->map[game->a][game->b] != '\n')
				game->others++;
		}
	}
}

//checking the content of map
int	ft_checkingcontent(t_game *game)
{
	if (game->player == 1
		&& game->collectable > 0
		&& game->exit > 0
		&& game->others == 0)
		return (1);
	return (0);
}

//checking map name
int	ft_checkfilename(char *str, char *s)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = ft_strlen(s) - 1;
	while (str[i] == s[j])
	{
		i--;
		j--;
	}
	if (j == -1)
		return (1);
	return (0);
}

// counting the line of map
int	ft_countmapline(char *file)
{
	char	*str;
	int		count;
	int		fd;

	count = 0;
	fd = open(file, O_RDWR);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
		{
			close(fd);
			break ;
		}
		free(str);
		count++;
	}
	return (count);
}

// reading the map line by line
int	ft_readmap(t_game *game, char *file)
{
	int			fd;
	char		*str;

	fd = open(file, O_RDWR);
	if (fd == -1)
		return (0);
	game->gameline = ft_countmapline(file);
	game->map = malloc(sizeof(char *) * (game->gameline + 1));
	if (!game->map)
		return (0);
	game->gameline = -1;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		game->map[++game->gameline] = str;
	}
	close(fd);
	game->map[++game->gameline] = NULL;
	game->width = game->gameline;
	game->height = ft_strlen(game->map[0]) - 1;
	return (1);
}
