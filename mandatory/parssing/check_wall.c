/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:05:33 by achahlao          #+#    #+#             */
/*   Updated: 2025/03/15 15:12:11 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"
#include "get_nextline_/get_next_line.h"
#include "../../libft/libft.h"

int	is_character(char c)
{
	return (c == '0' || c == 'S' || c == 'W' || c == 'E' || c == 'N');
}

static char	*ajouter_espaces(char *ligne, int taille)
{
	char	*nouvelle_ligne;
	int		i;

	i = 0;
	nouvelle_ligne = malloc(sizeof(char) * (taille + 1));
	if (!nouvelle_ligne)
		return (NULL);
	while (ligne[i] && ligne[i] != '\n')
	{
		nouvelle_ligne[i] = ligne[i];
		i++;
	}
	while (i < taille)
		nouvelle_ligne[i++] = ' ';
	nouvelle_ligne[taille] = '\0';
	return (nouvelle_ligne);
}

char	**transformer_carte_rectangulaire(char **carte, int *hauteur)
{
	char	**nouvelle_carte;
	int		i;
	int		largeur_max;

	(1) && (largeur_max = obtenir_largeur_max(carte, hauteur), i = 0);
	if (largeur_max < 0)
		return (ft_putstr_fd("Erreur : map absente\n", 2), NULL);
	nouvelle_carte = malloc(sizeof(char *) * (*hauteur + 1));
	if (!nouvelle_carte)
		return (NULL);
	while (carte[i])
	{
		nouvelle_carte[i] = ajouter_espaces(carte[i], largeur_max);
		if (!nouvelle_carte[i])
		{
			ft_putstr_fd("Problème de mémoire\n", 2);
			free_mat(nouvelle_carte);
			return (NULL);
		}
		i++;
	}
	nouvelle_carte[*hauteur] = NULL;
	return (nouvelle_carte);
}

static int	est_espace(char c)
{
	return (c == ' ');
}

int	verifier_murs(char **carte)
{
	char	**nouvelle_carte;
	int		hauteur;
	int		largeur;
	int		i;
	int		j;

	nouvelle_carte = transformer_carte_rectangulaire(carte, &hauteur);
	if (!nouvelle_carte)
		return (1);
	(1) && (largeur = ft_strlen(nouvelle_carte[0]), i = -1);
	while (++i < hauteur)
	{
		j = -1;
		while (++j < largeur)
		{
			if (is_character(nouvelle_carte[i][j]) && (
				j == 0 || j == largeur - 1 || i == 0 || i == hauteur - 1 ||
				(i > 0 && est_espace(nouvelle_carte[i - 1][j])) ||
				(i < hauteur - 1 && est_espace(nouvelle_carte[i + 1][j])) ||
				(j > 0 && est_espace(nouvelle_carte[i][j - 1])) ||
				(j < largeur - 1 && est_espace(nouvelle_carte[i][j + 1]))))
				return (ft_putstr_fd(ER, 2), free_mat(nouvelle_carte), 0);
		}
	}
	return (free_mat(nouvelle_carte), 1);
}
