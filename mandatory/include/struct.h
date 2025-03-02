#ifndef STRUCT_H
#define STRUCT_H

#include "./cube.h"
#include "../../MLX42/include/MLX42.h"

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

typedef struct s_map
{
	int	map[NUM_ROWS][NUM_COLOM];
    int sqaureFactorX;
    int sqaureFactorY;
}	t_map;

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
    int         speed;

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
    float   distance;
    float   rayAngle;
    bool	facingRight;
    float   xInter;
    bool	facingDown;
    float   yInter;
    t_hit   closestHit;
    t_point	*horizHitP;
    bool	facingUp;
    t_point	*vertiHitP;
    bool	facingLeft;
}   t_ray;

typedef struct s_cube
{
    mlx_t       *window;
    mlx_image_t *img;
    t_map       *map;
	t_texture   *texture;
    t_player    *player;
    t_ray       *ray;
    long        lastFameUpdate;
    float       constRayAngle;
    int         mybool;
}	t_cube;

#endif