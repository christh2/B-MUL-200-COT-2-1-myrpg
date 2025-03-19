#include<SFML/Window.h>
#include<SFML/System.h>
#include<SFML/Graphics.h>
#include<SFML/Audio/Sound.h>
#include<SFML/Audio/SoundBuffer.h>
#include<SFML/System/Export.h>
#include<SFML/Window/Mouse.h>
#include<SFML/Window/Event.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#ifndef _STRUCT_
    #define _STRUCT_

typedef struct hunter{
    sfVector2f scale_sprite4;
    sfClock *clock;
    sfTime time;
    sfSoundBuffer *soundbuffer;
    sfSound *sound;
    sfSoundBuffer *soundbuffer1;
    sfSound *sound1;
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *texture1;
    sfSprite *sprite1;
    sfTexture *texture2;
    sfSprite *sprite2;
    sfTexture *texture3;
    sfSprite *sprite3;
    sfTexture *texture4;
    sfSprite *sprite4;
    sfRenderWindow  *window;
    sfVector2i mouse1;
    sfBool boul;
    sfBool bouton;
    sfFont *font;
    sfText *text;
    sfFont *font1;
    sfText *text1;
    sfText *text2;
    sfText *text3;
    sfText *text4;
    sfText *text5;
    sfText *text6;
    sfText *text7;
    sfText *text8;
    sfText *text9;
    sfText *text10;
    sfText *text11;
    sfText *text12;
    sfText *text13;
    sfText *text14;
    sfUint32 ecran;
    sfSprite *sprite5;
    sfSprite *sprite6;
    sfSprite *sprite7;
    sfSprite *sprite8;
    sfTexture *texture9;
    sfSprite *sprite9;
    sfMusic *music;
    sfVector2f next;
    int f;
    int x;
    int y;
    sfImage *image;
    sfTexture *texture10;
    sfSprite *sprite10;
    sfView *view;
    sfSprite *sprite13;
}kratos;

struct button_s {
    sfRectangleShape * rect;
    sfText *text;
};

int compt_lignes(char *buffer);
int compt_cols(char *buffer);
char *simple_tab(char *str);
char **str_array(char *str);
int my_putstr(char const *str);
int my_putchar(char c);

#endif
