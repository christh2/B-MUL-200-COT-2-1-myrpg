/*
** EPITECH PROJECT, 2023
** paint.c
** File description:
** paint.c
*/

#include <SFML/Graphics.h>
#include <SFML/System/Sleep.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
//#include "my.h"

int compt_lignes(char *buffer);
int compt_cols(char *buffer);
char *simple_tab(char *str);
char **str_array(char *str);

int main(void)
{
    char *str = simple_tab("tttt"); int x = 0, y = 0;
    char **tab = str_array(str);
    /*for (; tab[x] != NULL; x++) {
      for (y = 0; tab[x][y] != '\0'; y++) {
      //printf("%c", tab[x][y]);
      }
      printf("\n");
      }*/ //full.png
    sfVideoMode mode = {800, 600, 32}; sfEvent event;
    sfVector2f position = {1, 1};
    //sfVector2f size = {300, 300};
    sfSprite *sol = sfSprite_create();
    sfTexture *img1 = sfTexture_createFromFile("green_grass.png", NULL);
    sfSprite_setTexture(sol, img1, sfTrue);
    sfVector2f scale1 = {3, 3}; sfSprite_setScale(sol, scale1);
    
    sfSprite *rou = sfSprite_create();
    sfTexture *img2 = sfTexture_createFromFile("full.png", NULL);
    sfSprite_setTexture(rou, img2, sfTrue);
    sfVector2f scale2 = {1.5, 1.5}; sfSprite_setScale(rou, scale2);
    
    sfRenderWindow *window = sfRenderWindow_create(mode, "paint", sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (event.type == sfEvtKeyPressed &&
                event.key.code == sfKeyEscape)
                sfRenderWindow_close(window);
        }
        position.y = 0;
        for (x = 0; tab[x] != NULL; x++) {
            for (y = 0; tab[x][y] != '\0'; y++) {
                if (tab[x][y] == 's') {
                    sfSprite_setPosition(sol, position);
                    sfRenderWindow_drawSprite(window, sol, NULL);
                } else if (tab[x][y] == 'r') {
                    //position.x += 5;
                    sfSprite_setPosition(rou, position);
                    sfRenderWindow_drawSprite(window, rou, NULL);
                } position.x += 5;
            } position.y += 5; position.x = 0;
        }
    }
    sfSprite_destroy(sol);
    sfTexture_destroy(img1);
    sfSprite_destroy(rou);
    sfTexture_destroy(img2);
    sfRenderWindow_destroy(window);
}
