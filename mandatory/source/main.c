/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:13:07 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/12 16:33:30 by moait-la         ###   ########.fr       */
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

int	main(void)
{
	t_cube	cube;
	char	*path;

	path = "/Users/moait-la/Desktop/42-Cube3D-chahlaoui/mandatory/parssing/test.cub";
	if (!parsing_final(path, &cube))
		return (1);
	init_mlx(&cube);
	allocations(&cube);
	setPLayerPosition(&cube);
	loatTextures(&cube);
	initStartingValues(&cube);
	setupHooks(&cube);
	return (0);
}
