#include "../include/cube.h"

void	renderCeilling(t_cube cube, int x, int wallTopPixel)
{
	int	k;

	k = -1;
	while ( ++k < wallTopPixel)
		myPixelPut(&cube, x, k, getColor(80, 80, 80, 255));
}

void	renderFloor(t_cube cube, int x, int wallBottomPixel) 
{
	while (++wallBottomPixel < HEIGHT)
	{
		if (x % 2 == 0)
			myPixelPut(&cube, x, wallBottomPixel, getColor(150, 150, 150, 255));
		else
			myPixelPut(&cube, x, wallBottomPixel, getColor(0, 0, 0, 255));
	}
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
	int		wallHeight;
	int		wallTopPixel;
	int		wallBottomPixel;
    int 	colom;

    colom = -1;
    while (++colom < NUM_RAYS)
    {		
		wallHeight = SCALINGFACTOR / cube.ray[colom].distance;
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

