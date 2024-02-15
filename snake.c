#include "snake.h"

void deplacement(int *pos_x, int *pos_y, char direction){
    switch(direction){
        case 'h':
            (*pos_y) -= 1;
            break;
        case 'g':
            (*pos_x) -= 1;
            break;
        case 'd':
            (*pos_x) += 1;
            break;
        case 'b':
            (*pos_y) += 1;
            break;
        case 'n':
            break;
    }
}

void pomme_manger(int x_s, int y_s, int *pos_x_pomme, int *pos_y_pomme,  int *score){
    //ajout d'un maillon
    //On incremente le score
    *score+=1;
    //On change les coordonees de la pomme
    (*pos_x_pomme) = rand() % 20;
    (*pos_y_pomme) = rand() % 10;
}
