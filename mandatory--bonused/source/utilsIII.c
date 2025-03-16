#include "../include/cube.h"

float	normalize(float angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = angle + (2 * M_PI);
	return angle;
}

int	rayFacingDirection(float angle, int mybool)
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
		if (cube->ray[colom].ray_angle > M_PI && cube->ray[colom].ray_angle < 2 * M_PI)
			return (-1);
	}
	else
		if (cube->ray[colom].ray_angle > M_PI / 2 && cube->ray[colom].ray_angle < 3 * (M_PI / 2))
			return (-1);
	return (0);
}

void	clear_image(t_cube *cube)
{
	ft_memset(cube->img->pixels, 0, cube->img->width * cube->img->height * 4);
}

void	free_all(t_cube *cube)
{
	int i;

    i = -1;
	while(++i < WIDTH)
		ft_free(cube->ray[i].horiz_hitp, cube->ray[i].verti_hitp);
}
