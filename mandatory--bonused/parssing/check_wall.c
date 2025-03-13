#include "parssing.h"
#include "get_nextline_/get_next_line.h"
#include "../../libft/libft.h"


static int	is_character(char c)
{
	return (c == '0' || c == 'S' || c == 'W' || c == 'E' || c == 'N');
}

static int obtenir_largeur_max(char **carte, int *hauteur)
{
    int i = 0;
    int largeur_max = 0;
    int longueur;

    if (!carte || !carte[0])
        return (-1);
    while (carte[i])
    {
        longueur = ft_strlen(carte[i]);
        if (longueur > largeur_max)
            largeur_max = longueur;
        i++;
    }
    *hauteur = i;
    return (largeur_max);
}

static char *ajouter_espaces(char *ligne, int taille)
{
    char *nouvelle_ligne = malloc(sizeof(char) * (taille + 1));
    int i = 0;

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

char **transformer_carte_rectangulaire(char **carte, int *hauteur)
{
    int i = 0;
    int largeur_max = obtenir_largeur_max(carte, hauteur);
    char **nouvelle_carte;

    if (largeur_max < 0)
        return(ft_putstr_fd("Erreur : map absente\n", 2), NULL);
    nouvelle_carte = malloc(sizeof(char *) * (*hauteur + 1));
    if (!nouvelle_carte)
        return NULL;
    while (carte[i])
    {
        nouvelle_carte[i] = ajouter_espaces(carte[i], largeur_max);
        if (!nouvelle_carte[i])
        {
            perror("Problème de mémoire");
            free_map(nouvelle_carte);
            return (NULL);
        }
        i++;
    }
    nouvelle_carte[*hauteur] = NULL;
    return (nouvelle_carte);
}

static int est_espace(char c)
{
    return (c == ' ');
}
void afficher_tableau1(char **str)
{
    int i = 0;

    while (str && str[i])
    {
        printf("%s  ---------%zu\n", str[i], ft_strlen(str[i]));
        i++;
    }
}
int verifier_murs(char **carte)
{
    int hauteur, largeur;
    char **nouvelle_carte = transformer_carte_rectangulaire(carte, &hauteur);
	printf("newww map\n");
	// afficher_tableau1(nouvelle_carte);
    int i = -1, j;

    if (!nouvelle_carte)
        return (1);
    largeur = ft_strlen(nouvelle_carte[0]);
	printf("langeur ------> %d\n", largeur );
	printf("hauteur ------> %d\n", hauteur );
    while(++i < hauteur)
    {
		j =-1;
        while (++j < largeur)
        {
            if (is_character(nouvelle_carte[i][j]) && (
                j == 0 || j == largeur - 1 || i == 0 || i == hauteur - 1 ||
                (i > 0 && est_espace(nouvelle_carte[i - 1][j])) ||
                (i < hauteur - 1 && est_espace(nouvelle_carte[i + 1][j])) ||
                (j > 0 && est_espace(nouvelle_carte[i][j - 1])) ||
                (j < largeur - 1 && est_espace(nouvelle_carte[i][j + 1]))))
            {
				printf("chaar est : %c  --- %d ---- %d\n",nouvelle_carte[i][j],i, j );
                ft_putstr_fd("Erreur : la crrarte n'est pas fermée par des murs\n", 2);
                free_map(nouvelle_carte);
                return (0);
            }
        }
    }
    return (free_map(nouvelle_carte),1);
}

