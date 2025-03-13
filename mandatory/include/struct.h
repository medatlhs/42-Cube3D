#ifndef STRUCT_H
#define STRUCT_H

#include "./cube.h"
#include "../../MLX42/include/MLX42.h"
#include "macros.h"
#include <stdbool.h>

typedef struct s_txture
{
    char    *path;
    char    *key;
} t_txture;

typedef struct s_texture
{
    mlx_texture_t	*no;
    mlx_texture_t	*ea;
    mlx_texture_t	*we;
    mlx_texture_t	*so;
    t_txture        *textures[4];
}	t_texture;

typedef struct s_point
{
    float	x;
    float	y;
}	t_point;

typedef struct s_player
{
    float       x;
    float       y;
    float       degree;
    int         fov;
    int         speed;

    float   rayInterX;
    float   rayInterY;

    bool	moveFront;
    bool	moveBack;
    bool    moveRight;
    bool    moveLeft;
    bool	rotateRight;
    bool	rotateLeft;
} 	t_player;

typedef enum s_hit
{
    VERTICAL,
    HORIZONTAL,
    VALIDHIT,
    UNKNOWN
}   t_hit;

typedef struct s_ray
{
    float   x_nearest;
    float   y_nearest;
    float   ray_angle;
    float   distance;
    bool	facingRight;
    bool	facingDown;
    bool	facingLeft;
    bool	facingUp;
    t_hit   closest_hit;
    t_point	*horiz_hitp;
    t_point	*verti_hitp;
}   t_ray;

typedef struct s_map
{
	int		*F;
	int		*C;
	char	**textures;
	char	**map;
    t_texture   *texture;
	char	testingMap[ROWS][COLOMS];
	int		colum;
	int		row;
}			t_map;

typedef struct s_cube
{
    mlx_t       *window;
    mlx_image_t *img;
    t_map       *map;
	t_texture   *texture;
    t_player    *player;
    t_ray       *ray;
    // long        lastFameUpdate;
    // bool        renderdBefore;
    // float       constRayAngle;
    // int         mybool;
}	t_cube;

#endif