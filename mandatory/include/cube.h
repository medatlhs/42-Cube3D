#ifndef CUBE_H
# define CUBE_H

#include "macros.h"
#include "struct.h"
#include "/Users/moait-la/my_libraries/MLX42/include/MLX42.h"
#include "/Users/moait-la/my_libraries/MLX42/include/MLX42.h"
#include "../../libft/libft.h"
#include <math.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdbool.h>

void	ft_error(char *errorMsj);
void	*ft_malloc(unsigned long size);
void	myPixelPut(t_cube *cube, int x, int y, uint32_t color);
void	getSquareFactor(t_cube *cube);
void	initStartingValues(t_cube *cube);
void	allocations(t_cube *cube);
void    ft_free(void *ptr, void *ptr2);
void	castAllRays(t_cube *cube);
void	setRayDirection(t_cube *cube, int colom);
void	getMap(t_cube *cube);
void	renderMapGrid(t_cube *cube);
void	renderPlayer(t_cube *cube);
int wallCheck(t_cube *cube, int	newX, int newY);
void	moveForward(t_cube *cube);
void    render_3dscene(t_cube data);
void	moveBack(t_cube *cube);
void	updatePosition(t_cube *cube);
void	keyPress(mlx_key_data_t keydata, void *param);
void    draw_x_sign(t_cube *cube, int x, int y, int size, int color);
void	getClosestHit(t_cube *cube, int colom);
double getTextureX(t_cube cube, int colom);
int	getTextureY(mlx_texture_t *texture, t_cube *cube, int y, int wall_h);
uint32_t	reverse_bytes(uint32_t c);
float normalize(float angle);
int inter_check(t_cube *mlx, float angle, float *inter, float *step, int is_horizon);
int rayFacingDirection(float angle, int mybool);
int	getPixel(t_cube *cube, int colom, bool flag);

#endif