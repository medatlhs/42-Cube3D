#include "../include/cube.h"
#define MINIMAPFACTOR 0.4
void	renderMapGrid(t_cube *cube)
{
	int	row;
	int	colom;
	int	x;
	int	y;

	row = -1;
	while (++row < NUM_ROWS)
	{
		colom = -1;
		while (++colom < NUM_COLOM )
		{
			y = -1;
			while (++y < cube->map->sqaureFactorY)
			{
				x = -1;
				while (++x < cube->map->sqaureFactorX)
				{
					int positionX = (colom * cube->map->sqaureFactorX) + x ;
					int positionY = (row * cube->map->sqaureFactorY) + y ;
					if (row >= NUM_ROWS || colom >= NUM_COLOM|| row < 0 || colom < 0)
                        return;
					int mapValue = cube->map->map[row][colom];
                    if (mapValue == 1)
                    	myPixelPut(cube, positionX*MINIMAPFACTOR, 
									positionY*MINIMAPFACTOR, 0x4B4B4B);
                    else if (mapValue == 0)
                        myPixelPut(cube, positionX*MINIMAPFACTOR, 
									positionY*MINIMAPFACTOR, getColor(255,255,255,255));
				}
			}
		}
	}
}

void	renderPlayer(t_cube *cube)
{
	int	playerSize;

	playerSize = 4;
	int	i = -playerSize;
	while (++i < playerSize)
	{
		int k = -playerSize;
		while (++k < playerSize)
		{
			mlx_put_pixel(cube->img,
				(cube->player->x * MINIMAPFACTOR) + k,
				(cube->player->y * MINIMAPFACTOR) + i, 0xFF0000);
		}
	}
}
