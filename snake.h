#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

typedef struct Membre
{
    int x;
    int y;
    struct Membre * suivant;

}Membre;

typedef struct FileSerpent
{
    int nbMembres;
    Membre * dernier;
    Membre * premier;
}FileSerpent;

///=====================================================================================
void initialiserSerpent(FileSerpent *serpent, int x, int y);
void enfile(FileSerpent *serpent, int x, int y);
void defile(FileSerpent *serpent);
///=====================================================================================

///=====================================================================================
void deplacement(FileSerpent *serpent, char direction);
void pommeMangee(FileSerpent *serpent, int *pos_x_pomme, int *pos_y_pomme, int *score);
///=====================================================================================

#endif // SNAKE_H_INCLUDED

