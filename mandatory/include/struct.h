/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:08:36 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/20 19:48:10 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./cube.h"
# include "../../MLX42/include/MLX42.h"
# include <stdbool.h>

typedef struct s_txture
{
	char	*path;
	char	*key;
}	t_txture;

typedef struct s_texture
{
	mlx_texture_t	*no;
	mlx_texture_t	*ea;
	mlx_texture_t	*we;
	mlx_texture_t	*so;
}	t_texture;

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_player
{
	float	x;
	float	y;
	float	degree;
	int		fov;
	int		speed;
	float	ray_inter_x;
	float	ray_inter_y;
	bool	move_front;
	bool	move_back;
	bool	move_right;
	bool	move_left;
	bool	rotate_right;
	bool	rotate_left;
}	t_player;

typedef enum s_hit
{
	VERTICAL,
	HORIZONTAL,
	VALIDHIT,
	UNKNOWN
}	t_hit;

typedef struct s_ray
{
	float	x_nearest;
	float	y_nearest;
	float	ray_angle;
	float	distance;
	bool	facing_right;
	bool	facing_down;
	bool	facing_left;
	bool	facing_up;
	t_hit	closest_hit;
	t_point	*horiz_hitp;
	t_point	*verti_hitp;
}	t_ray;

typedef struct s_map
{
	int			*f;
	int			*c;
	int			colum;
	int			row;
	char		**map;
	t_txture	*textur;
}	t_map;

typedef struct s_cube
{
	mlx_t		*window;
	mlx_image_t	*img;
	t_map		*map;
	t_texture	*texture;
	t_player	*player;
	t_ray		*ray;
}	t_cube;

#endif