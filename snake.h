#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

void deplacement(int *pos_x, int *pos_y, char direction);
void pomme_manger(int x_s, int y_s, int *pos_x_pomme, int *pos_y_pomme, int *score);


#endif // SNAKE_H_INCLUDED
