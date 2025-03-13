#ifndef CUBE_H
# define CUBE_H

#include <math.h>
#include <sys/time.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdbool.h>
#include "../../libft/libft.h"


int	check_texture(char **map);
void ft_putstr_fd(char *str, int fd);
int check_colors(char **map);
int validate_characters(char **map);
int	ft_check_charcters(char **map, char **(*fun2)(char **map));
int	ft_check_wall(char **map);
char	**get_walls(char **map);
int verifier_murs(char **carte);
void	free_map(char **str);
void afficher_tableau(char **str);
char **extract_map_interior(char **map);
void	free_mat(char **str);
char **transformer_carte_rectangulaire(char **carte, int *hauteur);
/************************** parssing **********************/

#endif