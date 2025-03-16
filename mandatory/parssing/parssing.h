#ifndef CUBE_H
# define CUBE_H

# define ER "map ne pas ferme \n"
#include <math.h>
#include <sys/time.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdbool.h>
#include "get_nextline_/get_next_line.h"
#include "../../libft/libft.h"
#include "../include/struct.h"
#include "../include/cube.h"



/************************** parssing **********************/
char	**parsing(char *file);
int	check_texture(char **map);
void ft_putstr_fd(char *str, int fd);
int check_colors(char **map);
int validate_characters(char **map);
int	ft_check_charcters(char **map, char **(*fun2)(char **map));
int	ft_check_wall(char **map);
char	**get_walls(char **map);
int verifier_murs(char **carte);
void	free_map(char **str);
void	free_mat(char **str);
void afficher_tableau(char **str);
char **extract_map_interior(char **map);
void	free_mat(char **str);
char **transformer_carte_rectangulaire(char **carte, int *hauteur);
int	ft_prsg_atoi(const char *str);
int	is_textures(char *str);
int	has_spaces_or_tabs(char *str);
int	is_texture(char *str);
int contains_only_whitespace(char *str);
void	trim_new_lines(char **map, int index);
int	get_max_line(char **map, int *size);
int	*get_colors(char **map, char *str);
int	obtenir_largeur_max(char **carte, int *hauteur);
int	*char_to_int(char **numbers_char);
char	*add_spaces(char *str, int size);
int	get_num_rows(char **map);
int	get_num_columns(char *row);
/************************** (fonction de text ) **********************/
void	print_textures(t_txture *textures);
void	afficher_tableau(char **str);
void	affiche_color(int *tab, int size);
void	print_textures(t_txture *textures);
#endif