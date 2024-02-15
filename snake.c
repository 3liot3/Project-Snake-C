#include "snake.h"

Membre* creerMembre(int x, int y)
{
    Membre* nouveauMembre = malloc(sizeof(Membre));
    nouveauMembre->x = x;
    nouveauMembre->y = y;
    nouveauMembre->suivant = NULL;
    return nouveauMembre;
}

void initialiserSerpent(FileSerpent *serpent, int x, int y)
{
    serpent->nbMembres = 1;
    serpent->premier = serpent->dernier = creerMembre(x, y);
}

void enfile(FileSerpent *serpent, int x, int y)
{
    Membre* nouveauMembre = creerMembre(x, y);

    if (serpent->nbMembres == 1)
    {
        serpent->premier->suivant = nouveauMembre;
    }
    else
    {
        serpent->dernier->suivant = nouveauMembre;
    }

    serpent->dernier = nouveauMembre;
    serpent->nbMembres++;
}

void defile(FileSerpent *serpent)
{
    if (serpent->nbMembres > 1)
    {
        Membre *ancienPremier = serpent->premier;
        serpent->premier = serpent->premier->suivant;
        free(ancienPremier);
        serpent->nbMembres--;
    }
}

void deplacement(FileSerpent *serpent, char direction)
{
    int nouvelleTeteX = serpent->dernier->x;
    int nouvelleTeteY = serpent->dernier->y;

    switch (direction)
    {
    case 'h': nouvelleTeteY--; break;
    case 'g': nouvelleTeteX--; break;
    case 'd': nouvelleTeteX++; break;
    case 'b': nouvelleTeteY++; break;
    case 'n': break;
    }

    defile(serpent);
    enfile(serpent, nouvelleTeteX, nouvelleTeteY);
}

void mettreAJourPomme(FileSerpent *serpent, int *pos_x_pomme, int *pos_y_pomme, int *score)
{
    enfile(serpent, *pos_x_pomme, *pos_y_pomme);
    (*score)++;
    *pos_x_pomme = rand() % 20;
    *pos_y_pomme = rand() % 10;
}
