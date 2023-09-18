/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:53:24 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/09/18 10:30:20 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_errors(t_data_maps *data, t_list *list)
{
	if (check_errors_textures(data->textures) == FALSE)
		return (FALSE);
	if (check_errors_colors(data) == FALSE)
		return (FALSE);
	if (check_errors_map(data, list) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	check_errors_textures(char **textures)
{
	int i;
	int	count;
	char **tmp;

	i = -1;
	count = 0;
	while (++i < 4)
	{
		if(textures[i])
			count++;
	}
	if (count != 4)
		return (FALSE);
	i = -1;
	while (++i < 4)
	{
		tmp = ft_split(textures[i], ' ');
		if (!tmp[1] || (tmp[1] && tmp[2]))
			return (FALSE);
		free(tmp);
	}
	return (TRUE);
}

int	check_errors_colors(t_data_maps *data)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		if (data->F[i] < 0 || data->F[i] > 255)
			return (FALSE);
		if (data->C[i] < 0 || data->C[i] > 255)
			return (FALSE);
	}
	return (TRUE);
}

int check_errors_map(t_data_maps *data, t_list *list)
{
	(void) list;
	t_corMap *posStart;

	posStart = init_corMap(data->map);
	if (posStart == FALSE)
		return (FALSE);
	if (check_intruderInMap(data->map) == FALSE)
		return (FALSE);
	data->posplayer = posStart;
	if (loopForMap(data->map, posStart, data->count) == FALSE)
		return (FALSE);
	return (TRUE);
}

int loopForMap(char **map, t_corMap *pos, int count)
{
	// t_listMap *cur;
	// t_listMap *first;
	// int	var;
	int i;
	int j;

	i = -1;
	// var = 0;
	// first = newlist(pos->x, pos->y);
	// cur = first;
	// t_listMap *tmp;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
			{
				if (i == 0 || j == 0 || i == count - 1 || j == ft_strlen(map[i]) - 2)
					return (FALSE);
				if (j > ft_strlen(map[i + 1]) || j > ft_strlen(map[i - 1]))
					return (FALSE);
			}
		}
		
		// var = 0;
		// if (map[cur->y][cur->x] == '0')
		// {
		// 	var = -1;
		// 	if (cur->y == 0 || cur->x == 0 || cur->y == count - 1 || cur->x == ft_strlen(map[cur->y]) - 2)
		//  			return (FALSE);
		// 	if ((map[cur->y + 1] && ft_strlen(map[cur->y + 1]) < cur->x) || ft_strlen(map[cur->y - 1]) < cur->x)
		// 		return (FALSE);
		// 	if (lstadd(first, newlist(cur->x + 1, cur->y), map, var) == FALSE)
		// 		return (FALSE);
		// 	if (lstadd(first, newlist(cur->x - 1, cur->y), map, var) == FALSE)
		// 		return (FALSE);
		// 	if (lstadd(first, newlist(cur->x, cur->y + 1), map, var) == FALSE)
		// 		return (FALSE);
		// 	if (lstadd(first, newlist(cur->x, cur->y - 1), map, var) == FALSE)
		// 		return (FALSE);
		// }
		// else
		// {
		// 	if (cur->x < ft_strlen(map[cur->y] - 2) && 
		// 		(map[cur->y][cur->x + 1] == '1' || map[cur->y][cur->x + 1] == '0'))
		// 			lstadd(first, newlist(cur->x + 1, cur->y), map, var);
		// 	if (cur->x > 0 && (map[cur->y][cur->x - 1] == '1'
		// 		|| map[cur->y][cur->x - 1] == '0'))
		// 			lstadd(first, newlist(cur->x - 1, cur->y), map,var);
		// 	if ((cur->y < count - 1 && map[cur->y + 1] && ft_strlen(map[cur->y + 1]) >= cur->x) && (map[cur->y + 1][cur->x] == '1'
		// 		|| map[cur->y + 1][cur->x] == '0'))
		// 			lstadd(first, newlist(cur->x, cur->y + 1), map, var);
		// 	if (cur->y < 0 && ft_strlen(map[cur->y - 1]) >= cur->x && (map[cur->y - 1][cur->x] == '1'
		// 		|| map[cur->y - 1][cur->x] == '0'))
		// 			lstadd(first, newlist(cur->x, cur->y - 1), map, var);
		// }
		// cur = cur->next;

	}
	return (TRUE);
}
