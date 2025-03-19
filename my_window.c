/*
** EPITECH PROJECT, 2023
** fghjk
** File description:
** fghjkl
*/

#include<SFML/Window.h>
#include<SFML/System.h>
#include<SFML/Graphics.h>
#include<SFML/Audio/Sound.h>
#include<SFML/Audio/SoundBuffer.h>
#include<SFML/System/Export.h>
#include<SFML/Window/Mouse.h>
#include<SFML/Window/Event.h>
#include<time.h>
#include <string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>
#include "my.h"

void music(kratos *str)
{
    str->soundbuffer = sfSoundBuffer_createFromFile("/home/fganfon/Downloads/chala_head_chala_mp3_47686.ogg");
    str->sound = sfSound_create();
    sfSound_setBuffer(str->sound, str->soundbuffer);
    sfSound_play(str->sound);
    sfSound_setLoop(str->sound, true);
}

struct button_s *init_button_option(kratos *str)
{
    struct button_s *button_s = malloc(sizeof(struct button_s *));
    sfVector2f position = {100, 1000};sfVector2f size = {1700, 20};
    button_s->rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(button_s->rect, sfBlue);
    sfRectangleShape_setSize(button_s->rect, size);
    sfRectangleShape_setPosition(button_s->rect, position);
    return button_s;
}

struct button_s *init_button(kratos *str)
{
    struct button_s *button_s = malloc(sizeof(struct button_s *));
    sfVector2f position = {100, 1000};sfVector2f size = {50, 20};
    button_s->rect = sfRectangleShape_create();
    sfColor orange = {255, 128, 0};
    sfRectangleShape_setFillColor(button_s->rect, sfRed);
    sfRectangleShape_setSize(button_s->rect, size);
    sfRectangleShape_setPosition(button_s->rect, position);
    return button_s;
}

int main(int ac, char **av)
{
    sfRenderWindow *window; 
    sfVideoMode video_mode = {1920, 1080, 32};
    window = sfRenderWindow_create(video_mode,"MY_RPG", sfClose | sfResize, NULL);
    sfEvent event; kratos *str = malloc(sizeof(*str));
    sfTexture *texture1 = sfTexture_createFromFile("/home/fganfon/Downloads/2410294.jpg", NULL);
    sfSprite *sprite1 = sfSprite_create();
    sfSprite_setTexture(sprite1, texture1, sfTrue);
    struct button_s *button_2 = init_button_option(str);
    struct button_s *button_3 = init_button(str); sfColor orange = {253, 105, 7};
    sfTime tmt; sfClock *lock; double p = 50; sfVector2f size = {p, 20};
    lock = sfClock_create(); sfTime tmp; float tp; float tm;
    music(str);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            event.type == sfEvtClosed ? sfRenderWindow_close(window) : 0;
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite1, NULL);
        sfRenderWindow_drawRectangleShape(window, button_2->rect, NULL);
        tmt = sfClock_getElapsedTime(lock);
        tm = tmt.microseconds / 10000.0;
        if (p < 1700) {
            p += rand() % 2; size = (sfVector2f){p, 20};
            sfRectangleShape_setSize(button_3->rect, size);
            sfRenderWindow_drawRectangleShape(window, button_3->rect, NULL);
        } else {
            sfRectangleShape_setFillColor(button_2->rect, sfRed);
        }
        
        sfRenderWindow_display(window);
    }
}
