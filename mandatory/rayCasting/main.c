/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:13:07 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/20 16:26:15 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	render_frame(void	*param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	clear_image(cube);
	update_position(cube);
	cast_all_rays(cube);
	render3d_scene(*cube);
	free_all(cube);
}

void f()
{
	system("leaks cube");
}

int	main(int ac, char **av)
{
	t_cube	cube;

	if (ac != 2)
		return (ft_error("too many arguments\n"), 1);
	if (!parsing_final(av[1], &cube))
		return (1);
	init_mlx(&cube);
	allocations(&cube);
	set_player_pos(&cube);
	load_textures(&cube);
	init_startings(&cube);
	setup_hooks(&cube);
	return (0);
}
