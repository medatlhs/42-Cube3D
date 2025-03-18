/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:19:33 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/18 17:21:17 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "./macros.h"
# include "./struct.h"
# include "../../MLX42/include/MLX42.h"
# include "../../libft/libft.h"
# include "../parssing/get_nextline_/get_next_line.h"
# include <math.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdbool.h>

void	ft_error(char *errorMsj);
void	*ft_malloc(unsigned long size);
void	my_pixel_put(t_cube *cube, int x, int y, uint32_t color);
void	init_startings(t_cube *cube);
void	allocations(t_cube *cube);
void	ft_free(void *ptr, void *ptr2);
void	cast_all_rays(t_cube *cube);
void	escape(t_cube *cube);
void	set_player_pos(t_cube *cube);
void	ft_close(void *param);
void	getMap(t_cube *cube);
void	free_all(t_cube *cube);
void	move_sides(t_cube *cube, int direction);
void	move_forward(t_cube *cube);
void	render3d_scene(t_cube cube);
void	move_back(t_cube *cube);
void	clear_image(t_cube *cube);
void	update_position(t_cube *cube);
void	key_press(mlx_key_data_t keydata, void *param);
void	get_closest_hit(t_cube *cube, int colom);
float	get_texture_x(t_cube data, int colom);
float	normalize(float angle);
void	get_horiz_inter(t_cube *cube, int colom);
void	get_verti_inter(t_cube *cube, int colom);
int		rayFacingDirection(float angle, int mybool);
int		get_pixel(t_cube *cube, int colom, bool flag);
int		get_color(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
int		wall_check(t_cube *cube, int newX, int newY);
int		get_texture_y(mlx_texture_t *texture, t_cube *cube, int y, int wall_h);
void	load_textures(t_cube *cube);
void	set_ray_direction(t_cube *cube, int colom);
void	setup_hooks(t_cube *cube);
void	init_mlx(t_cube *cube);
void	render_frame(void *param);

/************************** parssing **********************/
int		parsing_final(char *file, t_cube *cub);
char	**parsing(char *file);
int		check_texture(char **map);
void	ft_putstr_fd(char *str, int fd);
int		check_colors(char **map);
int		validate_characters(char **map);
int		ft_check_charcters(char **map, char **(*fun2)(char **map));
int		ft_check_wall(char **map);
char	**get_walls(char **map);
int		verifier_murs(char **carte);
void	free_map(char **str);
void	free_mat(char **str);
void	afficher_tableau(char **str);
char	**extract_map_interior(char **map);
void	free_mat(char **str);
char	**transformer_carte_rectangulaire(char **carte, int *hauteur);
int		ft_prsg_atoi(const char *str);
int		is_textures(char *str);
int		has_spaces_or_tabs(char *str);
int		is_texture(char *str);
int		contains_only_whitespace(char *str);
void	trim_new_lines(char **map, int index);
int		get_max_line(char **map, int *size);
int		*get_colors(char **map, char *str);
int		obtenir_largeur_max(char **carte, int *hauteur);
int		*char_to_int(char **numbers_char);
char	*add_spaces(char *str, int size);
int		get_num_rows(char **map);
int		get_num_columns(char *row);

/************************** (fonction de text ) **********************/
void	print_textures(t_txture *textures);
void	afficher_tableau(char **str);
void	affiche_color(int *tab, int size);
void	print_textures(t_txture *textures);

uint32_t		reverse_bytes(uint32_t c);
uint32_t		rgb_to_argb(int r, int g, int b);
mlx_texture_t	*get_texture(t_cube cube, t_ray ray);

#endif
