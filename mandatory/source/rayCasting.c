#include "../include/cube.h"

void	initRayData(t_cube *cube, float rayAngle, int colom)
{
	cube->ray[colom].horizHitP = (t_point *)ft_malloc(sizeof(t_point));
	cube->ray[colom].vertiHitP = (t_point *)ft_malloc(sizeof(t_point));
	cube->ray[colom].rayAngle = rayAngle;
	cube->ray[colom].closestHit = UNKNOWN;
}

void	castAllRays(t_cube *cube)
{
	float	firstRayAngleR;
	float	angleIncR;
	int		colom;

	firstRayAngleR = (cube->player->degree - (cube->player->fov/2)) * (M_PI / (float)180);
	// firstRayAngleR = normalize(firstRayAngleR);
	angleIncR = (cube->player->fov * M_PI/180) / (float)WIDTH;
	colom = -1;
	while (++colom < WIDTH)
	{
		firstRayAngleR = normalize(firstRayAngleR);
		initRayData(cube, firstRayAngleR, colom);
		setRayDirection(cube, colom);
		getHorizInter(cube, colom);
		getVertInter(cube, colom);
		getClosestHit(cube, colom);
		firstRayAngleR += angleIncR;
		// ft_free(cube->ray[colom].horizHitP, cube->ray[colom].vertiHitP, );
	}
}
