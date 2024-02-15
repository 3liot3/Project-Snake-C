#include "snake.h"

int main()
{
    int pos_x_pomme = 5;
    int pos_y_pomme = 5;
    int score = 0;
    char direction = 'n'; // -g : gauche -d : droite -h : haut -b : bas

    /// Initialisation du serpent
    FileSerpent serpent;
    initialiserSerpent(&serpent, 0, 0);

    while (1)
    {
        /// On efface la console
        system("cls"); // plus lent
        // printf("\033[H");
        // printf("\033[2J");

        /// On affiche le plateau de jeu
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                Membre *membre = serpent.premier;
                int membreAffiche = 0;

                while (membre != NULL)
                {
                    if (j == membre->x && i == membre->y)
                    {
                        printf("0");
                        membreAffiche = 1;
                        break;
                    }

                    membre = membre->suivant;
                }

                if (!membreAffiche)
                {
                    if (j == pos_x_pomme && i == pos_y_pomme)
                    {
                        printf("*");
                    }
                    else
                    {
                        printf("#");
                    }
                }
            }
            printf("\n");
        }

        printf("[ %d : %d ]", serpent.premier->x, serpent.premier->y);
        printf("\n[ %d : %d ]", pos_x_pomme, pos_y_pomme);
        printf("\n[ %d pts ]", score);

        if (serpent.premier->x == pos_x_pomme && serpent.premier->y == pos_y_pomme)
        {
            mettreAJourPomme(&serpent, &pos_x_pomme, &pos_y_pomme, &score);
        }

        // On ralentit l'exécution pour ne pas que ce soit trop rapide
        sleep(1);

        if (kbhit())
        {
            char touche = getch();
            switch (touche)
            {
            case 'z':
                direction = 'h';
                break;
            case 'q':
                direction = 'g';
                break;
            case 'd':
                direction = 'd';
                break;
            case 's':
                direction = 'b';
                break;
            }
        }

        deplacement(&serpent, direction);
    }

    return 0;
}

///TODO
//============================== ◄ SPAWN DE POMME ET COLLISION ► ========================================

//1 - Les pommes apparaissent à des endroits random du plateau (et pas sur le serpent)

//2 - Une fonction qui analyse la position (n+1) du serpent (de sa tete du moins) et qui verifie si on fonce dans un mur ou dans une pomme

//3 - Ecran 'GAME OVER'

//=================== ◄ FILE PR GERER L'AGRANDISSEMENT DU SERPENT ► ============================

//1 - Création d'une file contenant les position des parties du corps du serpent

//2 - Lorsque le serpent mange une pomme, on créer un nouveau maillon

//3 - La tête prends en valeur la nouvelle position (n+1) et la partit suivante prends en valeur la position 'actuelle' (n) ainsi de suite...

//4 - Une fonction qui parcours la liste permettant l'affichage du serpent (dans le main)

//================================ ◄ QUELQUES AJUSTEMENTS ► ==============================================

//1 - Le serpent ne doit pas pouvoir tourner a 180°

//2 - Le serpent de doit pas dépasser les bordures du plateau
