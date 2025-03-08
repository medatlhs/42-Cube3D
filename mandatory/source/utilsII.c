#include "../include/cube.h"

uint32_t rgb_to_argb(int r, int g, int b)
{     
    uint32_t color;

	color = 0;
    color |= 0xFF << 24; 
    color |= r << 16;
    color |= g << 8;      
    color |= b;
    return (color);
}

uint32_t	reverse_bytes(uint32_t c)
{
	uint32_t	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

void	myPixelPut(t_cube *cube, int x, int y, uint32_t color)
{
	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return ;
	mlx_put_pixel(cube->img, x, y, color);
}

void	getClosestHit(t_cube *cube, int colom)
{
	float	horizDist;
	float	vertiDist;

	horizDist = sqrt(pow(cube->ray[colom].horizHitP->x - cube->player->x, 2) +
		pow(cube->ray[colom].horizHitP->y - cube->player->y, 2));
	vertiDist = sqrt(pow(cube->ray[colom].vertiHitP->x - cube->player->x, 2) +
		pow(cube->ray[colom].vertiHitP->y - cube->player->y, 2));
	if (horizDist < vertiDist)
	{
		cube->ray[colom].closestHit = HORIZONTAL;
		cube->ray[colom].distance = horizDist * cos(cube->ray[colom].rayAngle -
			(cube->player->degree * (M_PI/180)));
		return ;
	}
	cube->ray[colom].closestHit = VERTICAL;
	cube->ray[colom].distance = vertiDist * cos(cube->ray[colom].rayAngle -
		(cube->player->degree * (M_PI/180)));
}
