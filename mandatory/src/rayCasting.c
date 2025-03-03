#include "../include/cube.h"

void	getHorizInter(t_cube *cube, int colom)
{
	cube->ray[colom].yInter = floor(cube->player->y / CELL_SIZE) * CELL_SIZE;
	if (cube->ray[colom].facingDown == true)
		cube->ray[colom].yInter += CELL_SIZE;
	cube->ray[colom].xInter = cube->player->x + (cube->ray[colom].yInter - cube->player->y) / (float)(tan(cube->ray[colom].rayAngle));

	float	xstep, ystep;
	ystep = CELL_SIZE;
	if (cube->ray[colom].facingUp == true)
		ystep *= -1;
	xstep = ystep /(float)(tan(cube->ray[colom].rayAngle));
	if (cube->ray[colom].facingLeft && xstep > 0)
		xstep *= -1;
	if (cube->ray[colom].facingRight && xstep < 0)
		xstep *= -1;

	float	posX, posY;
	posX = cube->ray[colom].xInter;
	posY = cube->ray[colom].yInter;
	while (posX > 0 && posY > 0 && posX < WIDTH && posY < HEIGHT)
	{
		// getPixel => -1 for up 1 for down
		if (!wallCheck(cube, posX, posY + getPixel(cube, colom, true)))
			break ;
		posX += xstep;
		posY += ystep;
	}

	cube->ray[colom].horizHitP->y = posY;
	cube->ray[colom].horizHitP->x = posX;
}

void getVertInter(t_cube *cube, int colom)
{
    cube->ray[colom].xInter = floor(cube->player->x / CELL_SIZE) * CELL_SIZE;
	if (cube->ray[colom].facingRight)
    	cube->ray[colom].xInter += CELL_SIZE;
	cube->ray[colom].yInter = cube->player->y + (cube->ray[colom].xInter - cube->player->x) * (tan(cube->ray[colom].rayAngle));

	float xstep, ystep;
	xstep = CELL_SIZE;
	if (cube->ray[colom].facingLeft == true)
		xstep *= -1;
	ystep = xstep * (tan(cube->ray[colom].rayAngle));
	if (cube->ray[colom].facingUp && ystep > 0)
		ystep *= -1;
	if (cube->ray[colom].facingDown && ystep < 0)
		ystep *= -1;

	float posX, posY;
	posX = cube->ray[colom].xInter;
	posY = cube->ray[colom].yInter;
	while (posX > 0 && posY > 0 && posX < WIDTH && posY < HEIGHT)
	{
		if (!wallCheck(cube, posX + getPixel(cube, colom, false), posY))
			break ;
		posX += xstep;
		posY += ystep;
	}
	cube->ray[colom].vertiHitP->x = posX;
	cube->ray[colom].vertiHitP->y = posY;
}

int	getColor(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a << 0);
}

void    render_3dscene(t_cube data)
{
    int i = -1;
    while (++i < NUM_RAYS)
    {
        float perpDistance = data.ray[i].distance * cos(data.ray[i].rayAngle - (data.player->degree * (M_PI/180)));
        float distanceProjPlane = (WIDTH / 2) / tan((data.player->fov * (M_PI / 180)) / 2);
        float projectedWallHeight = (data.map->sqaureFactorY / perpDistance) * distanceProjPlane;

        int wallStripHeight = (int)projectedWallHeight;

        int wallTopPixel = (HEIGHT / 2) - (wallStripHeight / 2);
        int wallBottomPixel = (HEIGHT / 2) + (wallStripHeight / 2);

        if (wallTopPixel < 0)
            wallTopPixel = 0;
        if (wallBottomPixel >= HEIGHT)
            wallBottomPixel = HEIGHT - 2;
        int k = wallTopPixel;

		int textureX = getTextureX(data, i);
		uint32_t *texturePixels = (uint32_t*)data.texture->we->pixels;
		// uint32_t *texturePixels = getTexture(data.ray[i].rayAngle);
        while (k <= wallBottomPixel)
        {
			float textureY = getTextureY(data.texture->we, &data, k, wallStripHeight);
			uint32_t position = (textureY * data.texture->we->width) + textureX;
			int color = texturePixels[position];
			myPixelPut(&data, i, k, reverse_bytes(color));
			k++;
        }
		int j = -1;
		while (++j < wallTopPixel)
			myPixelPut(&data, i, j, getColor(168, 168, 168, 255));
		while (++wallBottomPixel < HEIGHT)
			myPixelPut(&data, i, wallBottomPixel, getColor(18, 12, 9, 255));
    }
}

void	initRayData(t_cube *cube, float rayAngle, int colom)
{
	cube->ray[colom].closestHit = UNKNOWN;
	cube->ray[colom].rayAngle = rayAngle;
	cube->ray[colom].horizHitP = (t_point *)ft_malloc(sizeof(t_point));
	cube->ray[colom].vertiHitP = (t_point *)ft_malloc(sizeof(t_point));
	cube->ray[colom].closestHit = (t_hit)ft_malloc(sizeof(t_hit));
}

void	castAllRays(t_cube *cube)
{
	float	firstRayAngle;
	float	angleInc;
	int		colom;

	firstRayAngle = (cube->player->degree - cube->player->fov/2) * (M_PI / (float)180);
	firstRayAngle = normalize(firstRayAngle);
	angleInc = (cube->player->fov * M_PI/180) / (float)WIDTH;
	colom = -1;
	while (++colom < WIDTH)
	{
		initRayData(cube, firstRayAngle, colom);
		setRayDirection(cube, colom);
		getVertInter(cube, colom);
		getHorizInter(cube, colom);
		getClosestHit(cube, colom);
		firstRayAngle += angleInc;
		// ft_free(cube->ray[colom].horizHitP, cube->ray[colom].vertiHitP, );
	}
}
