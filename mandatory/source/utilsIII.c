#include "../include/cube.h"

float normalize(float angle)
{
    angle = fmod(angle, 2 * M_PI);
    if (angle < 0)
        angle = angle + (2 * M_PI);
    return angle;
}

int inter_check(t_cube *mlx, float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += mlx->map->sqaureFactorY;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
		{
			*inter += mlx->map->sqaureFactorX;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int rayFacingDirection(float angle, int mybool)
{
    if (!mybool)
        if (angle >=  M_PI && angle < M_PI * 2)
            return 0;
    if (mybool == 1)
        if (angle < M_PI && angle > 0)
            return 0;
    if (mybool == 2)
        if (angle > 270 * (M_PI/180) || angle < 90 * (M_PI/180))
            return 0;
    if (mybool == 3)
        if (angle < 270 * (M_PI/180) && angle > 90 * (M_PI/180))
            return 0;
   return 1;
}

int	getPixel(t_cube *cube, int colom, bool flag)
{
	if (flag)
	{
		if (cube->ray[colom].rayAngle > M_PI && cube->ray[colom].rayAngle < 2 * M_PI)
			return (-1);
	}
	else
		if (cube->ray[colom].rayAngle > M_PI / 2 && cube->ray[colom].rayAngle < 3 * (M_PI / 2))
			return (-1);
	return (1);
}
