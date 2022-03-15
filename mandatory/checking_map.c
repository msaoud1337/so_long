/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaoud <msaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 04:04:49 by msaoud            #+#    #+#             */
/*   Updated: 2022/02/16 04:13:45 by msaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

//checking the wall left and right
int	ft_wallrightleft(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if ((str[0] != '1') || (str[i - 1] != '1'))
		return (0);
	return (1);
}

// checking the the wall up and down
int	ft_wallupdown(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = ft_strlen(str) - 1;
	while (++i < j)
	{
		if (str[i] != '1')
			return (0);
	}
	return (1);
}

// checking the wall of the map 
int	ft_checkingthewall(t_game *game)
{
	int	i;

	i = game->width - 1;
	if (!ft_wallupdown(game->map[0]) || !ft_wallupdown(game->map[i]))
		return (0);
	i--;
	while (i >= 1)
	{
		if (ft_wallrightleft(game->map[i]) == 0)
			return (0);
		i--;
	}
	return (1);
}

// checking the len of the lanes of map 
int	ft_checkthemap(t_game *game)
{
	int		i;
	size_t	j;

	i = -1;
	j = game->height;
	while (game->map[++i])
	{
		if (j != ft_strlen(game->map[i]) - 1)
			return (0);
	}
	return (1);
}
