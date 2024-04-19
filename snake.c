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

    if(serpent == NULL || nouveauMembre == NULL){
        exit(EXIT_FAILURE);
    }

    nouveauMembre->x = x;
    nouveauMembre->y = y;

    nouveauMembre->suivant = NULL;

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

    /*
    Membre* nouveauMembre = creerMembre(x, y);

    if(serpent == NULL || nouveauMembre == NULL){
        exit(EXIT_FAILURE);
    }

    nouveauMembre->x = x;
    nouveauMembre->y = y;
    nouveauMembre->suivant = NULL;

    if(serpent->premier != NULL){
        Membre *elementActuel = serpent->premier;
        while(elementActuel->suivant != NULL){
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveauMembre;
    }
    else{
        serpent->premier = nouveauMembre;
    }
    */


}

void nouveauMembre(FileSerpent *serpent, int x, int y){

    Membre* nouveauMembre = creerMembre(x, y);

    if(serpent == NULL || nouveauMembre == NULL){
        exit(EXIT_FAILURE);
    }

    nouveauMembre->x = x;
    nouveauMembre->y = y;
    nouveauMembre->suivant = NULL;

    if(serpent->premier != NULL){
        Membre *elementActuel = serpent->premier;
        while(elementActuel->suivant != NULL){
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveauMembre;
    }
    else{
        serpent->premier = nouveauMembre;
    }
}

void defile(FileSerpent *serpent)
{
    if(serpent == NULL){
        exit(EXIT_FAILURE);
    }

    if(serpent->premier != NULL){
        Membre *elementDefile = serpent->premier;
        serpent->premier = elementDefile->suivant;
        free(elementDefile);
    }
    /*
    if (serpent->nbMembres > 1)
    {
        Membre *ancienPremier = serpent->premier;
        serpent->premier = serpent->premier->suivant;
        free(ancienPremier);
        serpent->nbMembres--;
    }
    */
}

void deplacement(FileSerpent *serpent, char direction)
{
    if(direction == 'h' || direction == 'g' || direction == 'd' || direction == 'b'){
        int nouvelleTeteX = serpent->dernier->x;
        int nouvelleTeteY = serpent->dernier->y;
            switch (direction){
                case 'h':
                    nouvelleTeteY-=1;
                    break;
                case 'g':
                    nouvelleTeteX-=1;
                    break;
                case 'd':
                    nouvelleTeteX+=1;
                    break;
                case 'b':
                    nouvelleTeteY+=1;
                    break;
            }
            enfile(serpent, nouvelleTeteX, nouvelleTeteY);
            defile(serpent);
    }
}

void mettreAJourPomme(FileSerpent *serpent, int *pos_x_pomme, int *pos_y_pomme, int *score)
{
    (*score)++;
    nouveauMembre(serpent, *pos_x_pomme, *pos_y_pomme);
    *pos_x_pomme = (rand() % 21)+1;
    *pos_y_pomme = (rand() % 11)+1;
}
