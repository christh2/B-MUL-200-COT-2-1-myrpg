/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** rpg
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
#include <SFML/Audio.h>
#include"struct.h"

void manage_mouse1(sfEvent event, kratos *str)
{
    str->mouse1 = sfMouse_getPositionRenderWindow(str->window);
    if (str->mouse1.x >= 889 && str ->mouse1.x <= 1026) {
        if (str ->mouse1.y >= 467 && str ->mouse1.y <= 583) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                str->boul = true;
            }
        }
    }
}

void button_start(sfEvent event, kratos *str)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyC) {
        str->boul = false;
        str->bouton = true;
    }
}

/*void music1(kratos *str, sfEvent event)
{
    str->soundbuffer = sfSoundBuffer_createFromFile("click.ogg");
    str->sound = sfSound_create();
    sfSound_setBuffer(str->sound, str->soundbuffer);
    sfSound_play(str->sound);
    }*/

void music(kratos *str)
{
    str->music = sfMusic_createFromFile("game_of_thrones_main_theme_extended_hd_aac_30565.ogg");
    sfMusic_play(str->music);
    sfMusic_setLoop(str->music, true);
}

struct button_s *init_button_option(kratos *str)
{
    struct button_s *button_s = malloc(sizeof(struct button_s *));
    sfVector2f position = {100, 900};sfVector2f size = {1700, 20};
    button_s->rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(button_s->rect, sfGreen);
    sfRectangleShape_setSize(button_s->rect, size);
    sfRectangleShape_setPosition(button_s->rect, position);
    return button_s;
}

struct button_s *init_button(kratos *str)
{
    struct button_s *button_s = malloc(sizeof(struct button_s *));
    sfVector2f position = {100, 900};sfVector2f size = {50, 20};
    button_s->rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(button_s->rect, sfYellow);
    sfRectangleShape_setSize(button_s->rect, size);
    sfRectangleShape_setPosition(button_s->rect, position);
    return button_s;
}

sfSprite *show_sprite(char *c, sfVector2f position)
{
    sfTexture *texture = sfTexture_createFromFile(c, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, position);
    return sprite;
}

sfText *show_menu(char *c, sfVector2f position)
{
    sfFont *font = sfFont_createFromFile("GODOFWAR.TTF");
    sfText *text = sfText_create();sfText_setString(text, c);
    sfText_setFont(text, font);sfText_setCharacterSize(text, 50);
    sfText_setColor(text, sfBlue);
    sfText_setPosition(text, position);
    return text;
}

char *my_strcat(char *dest, char c)
{
    if (dest == NULL) {
        char *str = malloc(sizeof(char *) *2);
        str[0] = c;
        str[1] = '\0';
        return str;
    }
    int f = strlen(dest), g = 0;
    char *str = malloc(sizeof(char) * (f + 2));
    for (g = 0; dest[g] != '\0'; g++) {
        str[g] = dest[g];
    }
    str[g] = c;
    str[g + 1] = '\0';
    return str;
}

int structure(int ac, char **av)
{
    struct stat buf;
    stat("history", &buf);
    int size = buf.st_size;
    return buf.st_size;
}

char *read_all(int ac, char **av)
{
    int i, size = structure(ac, av);
    int fd = open("history", O_RDONLY);
    char *map; char **tab;
    map = malloc(sizeof(char) * size);
    read(fd, map, size);
    close(fd);
    return map;
}

int use_sprite(kratos *str)
{
    str->texture = sfTexture_createFromFile("olya-kolosha-3.jpg", NULL);
    str->texture1 = sfTexture_createFromFile("menu.jpg", NULL);
    str->sprite = sfSprite_create();
    sfSprite_setTexture(str->sprite, str->texture, sfTrue);
    str->sprite1 = sfSprite_create();
    sfSprite_setTexture(str->sprite1, str->texture1, sfTrue);
    str->texture2 = sfTexture_createFromFile("wp4082527.jpg", NULL);
    str->sprite2 = sfSprite_create();
    sfSprite_setTexture(str->sprite2, str->texture2, sfTrue);
    str->texture4 = sfTexture_createFromFile("first.jpg", NULL);
    str->sprite4 = sfSprite_create();
    sfSprite_setTexture(str->sprite4, str->texture4, sfTrue);
    sfVector2f position = {1000, 500};
    str->sprite13 = show_sprite("discusssion.png", position);
}

sfBool is_button_clicked(sfText *text, sfMouseMoveEvent* mouse)
{
    sfFloatRect rect = sfText_getGlobalBounds(text);
    sfFloatRect_contains(&rect, mouse->x, mouse->y);
}

sfBool is_button_clicked2(sfText *text, sfMouseButtonEvent* mouse)
{
    sfFloatRect rect = sfText_getGlobalBounds(text);
    sfFloatRect_contains(&rect, mouse->x, mouse->y);
}

sfBool is_sprite_clicked(sfSprite *sprite, sfMouseButtonEvent* mouse)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);
    sfFloatRect_contains(&rect, mouse->x, mouse->y);
}

void hover_sprite(kratos *str, sfEvent event)
{
    float i = sfMusic_getVolume(str->music);
    if (is_sprite_clicked(str->sprite5, &event.mouseButton)) {
        i++;
        if (i > 100.f) i = 100.f;
    } else if (is_sprite_clicked(str->sprite6, &event.mouseButton)) {
        i--;
        if (i < 0) i = 0;
    }
    sfMusic_setVolume(str->music, i);
}

void hover_event(kratos *str, sfEvent event)
{
    (is_button_clicked(str->text4, &event.mouseMove)) ? sfText_setColor(str->text4, sfRed) :
        sfText_setColor(str->text4, sfBlue);
    (is_button_clicked(str->text5, &event.mouseMove)) ? sfText_setColor(str->text5, sfRed) :
        sfText_setColor(str->text5, sfBlue);
    (is_button_clicked(str->text6, &event.mouseMove)) ? sfText_setColor(str->text6, sfRed) :
        sfText_setColor(str->text6, sfBlue);
    (is_button_clicked(str->text7, &event.mouseMove)) ? sfText_setColor(str->text7, sfRed) :
        sfText_setColor(str->text7, sfBlue);
    (is_button_clicked(str->text8, &event.mouseMove)) ? sfText_setColor(str->text8, sfRed) :
        sfText_setColor(str->text8, sfBlue);
    (is_button_clicked(str->text9, &event.mouseMove)) ? sfText_setColor(str->text9, sfRed) :
        sfText_setColor(str->text9, sfBlue);
}

void draw_start_menu(sfRenderWindow *window, kratos *str, sfEvent event)
{
    sfRenderWindow_drawText(str->window, str->text3, NULL);
    sfRenderWindow_drawText(str->window, str->text4, NULL);
    sfRenderWindow_drawText(str->window, str->text5, NULL);
    sfRenderWindow_drawText(str->window, str->text6, NULL);
    sfRenderWindow_drawText(str->window, str->text7, NULL);
    hover_event(str, event);
    (is_button_clicked2(str->text4, &event.mouseButton)) ? str->f = 1 : 0;
    (is_button_clicked2(str->text5, &event.mouseButton)) ? str->f = 2 : 0;
    (is_button_clicked2(str->text6, &event.mouseButton)) ? str->f = 3 : 0;
    (is_button_clicked2(str->text7, &event.mouseButton)) ?
        sfRenderWindow_close(str->window) : 0;
    (is_button_clicked2(str->text8, &event.mouseButton)) ? str->f = 4 : 0;
    (is_button_clicked2(str->text9, &event.mouseButton)) ? str->ecran = sfFullscreen : 0;
}

void text_use(kratos *str, sfVector2f pose)
{
    sfVector2f position = {850, 200}; sfVector2f position1 = {850, 400};
    str->text3 = show_menu("GOT", position); sfVector2f position2 = {850, 500};
    str->text4 = show_menu("START", position1);sfVector2f position3 = {850, 600};
    str->text5 = show_menu("SETTINGS", position2);sfVector2f position4 = {850, 700};
    str->text6 = show_menu("CONTINUE", position3);sfVector2f position5 = {850, 950};
    str->text7 = show_menu("EXIT", position4); sfVector2f position6 = {1000, 100};
    str->text8 = show_menu("BACK", position5);sfVector2f position7 = {1000, 200};
    str->text9 = show_menu("FULLSCREEN:", position6);sfVector2f position8 = {1000, 300};
    str->text10 = show_menu("VOLUME", position7); sfVector2f position9 = {1000, 400};
    str->text11 = show_menu("SOUND:", position8);str->text12 = show_menu("MUSIC:", position9);
    sfVector2f position10 = {1000, 500}; str->text13 = show_menu("HOW TO PLAY", position10);
}

void settings(kratos *str, sfEvent event)
{
    sfRenderWindow_drawSprite(str->window, str->sprite4, NULL);
    sfRenderWindow_drawText(str->window, str->text9, NULL);
    sfRenderWindow_drawText(str->window, str->text10, NULL);
    sfRenderWindow_drawText(str->window, str->text11, NULL);
    sfRenderWindow_drawText(str->window, str->text12, NULL);
    sfRenderWindow_drawText(str->window, str->text13, NULL);
    sfRenderWindow_drawText(str->window, str->text8, NULL);
    sfVector2f position9 = {1250, 400};
    str->sprite5 = show_sprite("buttons/button_plus.png", position9);
    sfRenderWindow_drawSprite(str->window, str->sprite5, NULL);
    sfVector2f position10 = {1400, 400};
    str->sprite6 = show_sprite("buttons/button_minus.png", position10);
    sfRenderWindow_drawSprite(str->window, str->sprite6, NULL);
    hover_sprite(str, event);
}

/*void move_down(kratos *str)
{
    int p = 0;
    p = sfSprite_getPosition(str->sprite8).y;
    p = p / 20 % 4;
    p = p * 30;
    sfIntRect rect1 = {p, 0, 30, 45};
    sfSprite_setTextureRect(str->sprite8, rect1);
    str->next = sfSprite_getPosition(str->sprite8);
    str->next.y += 5; str->y += 5;
    sfSprite_setPosition(str->sprite8, str->next);
    }*/

void move_up(kratos *str)
{
    int p = 0;
    p = sfSprite_getPosition(str->sprite9).y;
    p = p / 20 % 8;
    p = p * 63;
    sfIntRect rect1 = {p, 0, 63, 67};
    sfSprite_setTextureRect(str->sprite9, rect1);
    str->next = sfSprite_getPosition(str->sprite9);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(str->sprite9);
    sfColor color = sfImage_getPixel(str->image, rect2.left, rect2.top - 5);
    printf("%d %d %d", color.r, color.g, color.b);
    if (color.r != 0 && color.g != 0 && color.b != 0) {
        str->next.y -= 5; str->y -= 5;
    }
    if (color.r == 86.7 && color.g == 90.4 && color.b == 11.5) {
        str->next.y -= 5;
        sfRenderWindow_drawSprite(str->window, str->sprite13, NULL);
    }
    sfSprite_setPosition(str->sprite9, str->next);
}

void move_down(kratos *str)
{
    int p = 0;
    p = sfSprite_getPosition(str->sprite9).y;
    p = p / 20 % 8;
    p = p * 63;
    sfIntRect rect1 = {p, 135, 63, 67};
    sfSprite_setTextureRect(str->sprite9, rect1);
    str->next = sfSprite_getPosition(str->sprite9);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(str->sprite9);
    sfColor color = sfImage_getPixel(str->image, rect2.left, rect2.top + 5 + 67);
    if (color.r != 0 && color.g != 0 && color.b != 0) {
        str->next.y += 5; str->y += 5;
    }
    sfSprite_setPosition(str->sprite9, str->next);
}

void move_left(kratos *str)
{
    int p = 0;
    p = sfSprite_getPosition(str->sprite9).x;
    p = p / 20 % 8;
    p = p * 63;
     sfIntRect rect1 = {p, 73, 63, 67};
    sfSprite_setTextureRect(str->sprite9, rect1);
    str->next = sfSprite_getPosition(str->sprite9);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(str->sprite9);
    sfColor color = sfImage_getPixel(str->image, rect2.left - 5, rect2.top);
    if (color.r != 0 && color.g != 0 && color.b != 0) {
        str->next.x -= 5; str->x -= 5;
    }
    sfSprite_setPosition(str->sprite9, str->next);
}

void move_right(kratos *str)
{
    int p = 0;
    p = sfSprite_getPosition(str->sprite9).x;
    p = p / 20 % 8;
    p = p * 63;
    sfIntRect rect1 = {p, 199, 63, 67};
    sfSprite_setTextureRect(str->sprite9, rect1);
    str->next = sfSprite_getPosition(str->sprite9);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(str->sprite9);
    sfColor color = sfImage_getPixel(str->image, rect2.left + 5 + 63, rect2.top);
    if (color.r != 0 && color.g != 0 && color.b != 0) {
        str->next.x += 5; str->x += 5;
    }
    sfSprite_setPosition(str->sprite9, str->next);
}

int main(int ac, char **av)
{
    kratos *str = malloc(sizeof(*str));
    sfEvent event;
    str->ecran = sfClose | sfResize;
    sfVideoMode video_mode = {1920, 1080, 32}; sfVector2f position = {1, 1}; double p = 50;
    str->window = sfRenderWindow_create(video_mode,"MY_RPG", str->ecran, NULL);
    sfVector2f size = {p, 20};
    use_sprite(str);
    sfVector2f scale_button = {0.50, 0.50}; sfTime tmt; sfClock *lock;
    lock = sfClock_create(); sfTime tmp; float tp;
    sfVector2f pose_button = {880, 450}; float tm;
    sfVector2f pose = {860, 250};
    struct button_s *button_2 = init_button_option(str);
    struct button_s *button_3 = init_button(str); 
    music(str);int i = 0; char *map;
    str->boul = false;char *tab = malloc(sizeof(char) * (strlen(map) + 2));
    str->bouton = false;
    text_use(str, pose);
    str->font1 = sfFont_createFromFile("GODOFWAR.TTF");
    str->text1 = sfText_create();
    sfTexture *texture = sfTexture_createFromFile("Image(1).png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f position1 = {500, 200};
    sfSprite_setTexture(sprite, texture, sfTrue); int w = 0;
    str->texture9 = sfTexture_createFromFile("player.png", NULL);
    str->sprite9 = sfSprite_create();
    sfSprite_setTexture(str->sprite9, str->texture9, sfTrue);
    sfSprite_setPosition(str->sprite9, position1);
    sfIntRect rect = {0, 0, 63, 67};
    sfSprite_setTextureRect(str->sprite9, rect);
    str->image = sfImage_createFromFile("Image_1_.png");
    str->texture10 = sfTexture_createFromImage(str->image, NULL);
    str->sprite10 = sfSprite_create();
    str->view = sfView_create();
    while (sfRenderWindow_isOpen(str->window)) {
        while (sfRenderWindow_pollEvent(str->window, &event)) {
            event.type == sfEvtClosed ? sfRenderWindow_close(str->window) : 0;
            (event.type == sfEvtKeyPressed) & (event.key.code == sfKeyEscape) ?
                sfRenderWindow_close(str->window) : 0;
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS) {
                w = 1;
            }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
                sfSprite_setTextureRect(str->sprite9, rect);
                move_up(str);
            }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
                sfSprite_setTextureRect(str->sprite9, rect);
                move_down(str);
            }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
                sfSprite_setTextureRect(str->sprite9, rect);
                move_left(str);
            }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
                sfSprite_setTextureRect(str->sprite9, rect);
                move_right(str);
            }
        }
        sfRenderWindow_clear(str->window, sfBlack);
        if (!str->boul) {
            sfRenderWindow_drawSprite(str->window, str->sprite, NULL);
            sfRenderWindow_drawRectangleShape(str->window, button_2->rect, NULL);
            tmt = sfClock_getElapsedTime(lock);
            tm = tmt.microseconds / 10000.0;
            if (p < 1700) {
                p += rand() % 2; size = (sfVector2f){p, 20};
                sfRectangleShape_setSize(button_3->rect, size);
                sfRenderWindow_drawRectangleShape(str->window, button_3->rect, NULL);
            } else {
                sfRectangleShape_setFillColor(button_2->rect, sfYellow);
                sfRenderWindow_drawSprite(str->window, str->sprite, NULL);
                sfRenderWindow_drawSprite(str->window, str->sprite1, NULL);
                draw_start_menu(str->window, str, event);
            }
        }
        if (str->f == 2) {
            settings(str, event);
        } else if (str->f == 4) {
            draw_start_menu(str->window, str, event);
        }
        if (str->f == 1) {
            sfRenderWindow_drawSprite(str->window, str->sprite2, NULL);        
            tmp = sfClock_getElapsedTime(lock);
            tp = tmt.microseconds / 100000.0;
            if (tp > 0.1 && i < strlen(map)) {
                map = read_all(ac, av);
                tab = my_strcat(tab, map[i]);
                sfText_setString(str->text1, tab); sfText_setFont(str->text1, str->font1);
                sfText_setCharacterSize(str->text1, 20); sfText_setColor(str->text1, sfCyan);
                i++;
            }
            sfRenderWindow_drawText(str->window, str->text1, NULL);
            sfVector2f position11 = {900, 900}; str->text14 = show_menu("PRESS ENTRER TO LOAD THE GAME", position11);
            sfRenderWindow_drawText(str->window, str->text14, NULL);
        }
        if (w == 1) {
            sfRenderWindow_drawSprite(str->window, str->sprite10, NULL);
            sfRenderWindow_drawSprite(str->window, sprite, NULL);
            sfRenderWindow_drawSprite(str->window, str->sprite9, NULL);
            sfView_move(str->view, (sfVector2f){str->x, str->y});
            sfRenderWindow_setView(str->window, str->view);
            str->x = 0; str->y = 0;
        }
        sfRenderWindow_display(str->window);
    }
}
