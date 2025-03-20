/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:34:32 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/20 16:16:46 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	check_release(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->move_front = false;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->move_back = false;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->rotate_right = false;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->rotate_left = false;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->move_right = false;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->move_left = false;
}

void	ft_clean(t_cube *cube)
{
	int	i;

	i = -1;
	while (++i < cube->map->row)
		free(cube->map->map[i]);
}

void	escape(t_cube *cube)
{
	ft_free(NULL, cube->player);
	ft_free(NULL, cube->ray);
	ft_clean(cube);
	ft_putstr_fd("closed!\n", 1);
	exit(0);
}

void	ft_close(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	ft_free(cube->map, cube->player);
	ft_free(cube->ray, cube->texture);
	ft_putstr_fd("closed!\n", 1);
	exit(0);
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		escape((t_cube *)param);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->move_front = true;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->move_back = true;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->rotate_right = true;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->rotate_left = true;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->move_right = true;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->move_left = true;
	else
		check_release(keydata, param);
}
