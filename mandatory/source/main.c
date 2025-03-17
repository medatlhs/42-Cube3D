/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:13:07 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/17 17:21:04 by moait-la         ###   ########.fr       */
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
int	main(void)
{
	t_cube	cube;
	char	*path;

	atexit(f);
	path = "/Users/moait-la/Downloads/42-Cube3D-chahlaoui/mandatory/parssing/test.cub";
	printf("%s\n",path);
	if (!parsing_final(path, &cube))
		return (1);
	
	init_mlx(&cube);
	allocations(&cube);
	set_player_pos(&cube);
	load_textures(&cube);
	init_startings(&cube);
	setup_hooks(&cube);
	return (0);
}
