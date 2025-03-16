#ifndef CUBE_H
# define CUBE_H

#include "./macros.h"
#include "./struct.h"
#include "../../MLX42/include/MLX42.h"
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
void	cast_all_rays(t_cube *cube);
void	escape(t_cube *cube);
void	setPLayerPosition(t_cube *cube);
void	ft_close(void* param);
void	renderMiniMap(t_cube *cube);
void	setRayDirection(t_cube *cube, int colom);
void	getMap(t_cube *cube);
void	free_all(t_cube *cube);
void	renderMapGrid(t_cube *cube);
void	renderPlayer(t_cube *cube);
void    move_sides(t_cube *cube, int direction);
void	move_forward(t_cube *cube);
void    render3d_scene(t_cube cube);
void	renderPlayer(t_cube *cube);
void	move_back(t_cube *cube);
void	clear_image(t_cube *cube);
void    castRay(t_cube *cube, t_player *player);
void	update_position(t_cube *cube);
void	key_press(mlx_key_data_t keydata, void *param);
void    draw_x_sign(t_cube *cube, int x, int y, int size, int color);
void	getClosestHit(t_cube *cube, int colom);
int	    getColor(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
float	getTextureX(t_cube data, int colom);        
float   normalize(float angle);
void	get_horiz_inter(t_cube *cube, int colom);
void    get_verti_inter(t_cube *cube, int colom);
int     inter_check(t_cube *mlx, float angle, float *inter, float *step, int is_horizon);
int     rayFacingDirection(float angle, int mybool);
int	    getPixel(t_cube *cube, int colom, bool flag);
int	    get_texture_x(mlx_texture_t *texture, t_cube *cube);
int     wall_check(t_cube *cube, int	newX, int newY);
void    loatTextures(t_cube *cube);
int	    getTextureY(mlx_texture_t *texture, t_cube *cube, int y, int wall_h);
uint32_t reverse_bytes(uint32_t c);
void	setupHooks(t_cube *cube);
void	init_mlx(t_cube *cube);
void	render_frame(void *param);
uint32_t rgb_to_argb(int r, int g, int b);
mlx_texture_t	*get_texture(t_cube *cube);


int parsing_final(char *file, t_cube *cub);
#endif