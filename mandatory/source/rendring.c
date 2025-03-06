#include "../include/cube.h"

void	renderCeilling(t_cube cube, int x, int wallTopPixel)
{
	int	k;

	k = -1;
	while ( ++k < wallTopPixel)
		myPixelPut(&cube, x, k, getColor(168, 168, 168, 255));
}

void	renderFloor(t_cube cube, int x, int wallBottomPixel) 
{
	while (++wallBottomPixel < HEIGHT)
		myPixelPut(&cube, x, wallBottomPixel, getColor(18, 12, 9, 255));
}

void	renderStripe(t_cube cube, int wallHeight, int colom, int topPixel, int BottomPixel)
{
    int 		k;
	int			pixelPos;
	int 		textureX;
	float 		textureY;
	uint32_t	*texturePixels;

	k = topPixel;
	textureX = getTextureX(cube, colom);
	texturePixels = (uint32_t*)cube.texture->we->pixels;
    while (k <= BottomPixel)
    {
		textureY = getTextureY(cube.texture->we, &cube, k, wallHeight);
		pixelPos = (textureY * cube.texture->we->width) + textureX;
		myPixelPut(&cube, colom, k, reverse_bytes(texturePixels[pixelPos]));
		k++;
    }
}

void    render3Dscene(t_cube cube)
{
	int		distanceProjPlane;
	int		wallHeight;
	int		wallTopPixel;
	int		wallBottomPixel;
    int 	colom;

    colom = -1;
    while (++colom < NUM_RAYS)
    {
        distanceProjPlane = (WIDTH / 2) / tan((cube.player->fov * (M_PI / 180)) / 2);
        wallHeight = (CELL_SIZE / cube.ray[colom].distance) * distanceProjPlane;
        wallTopPixel = (HEIGHT / 2) - (wallHeight / 2);
        wallBottomPixel = (HEIGHT / 2) + (wallHeight / 2);
		if (wallTopPixel < 0)
            wallTopPixel = 0;
    	if (wallBottomPixel >= HEIGHT)
        	wallBottomPixel = HEIGHT - 1;
		renderStripe(cube, wallHeight, colom, wallTopPixel, wallBottomPixel);
		renderCeilling(cube, colom, wallTopPixel);
		renderFloor(cube, colom, wallBottomPixel);
    }
}

