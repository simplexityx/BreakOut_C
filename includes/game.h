#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include "manager.h"

#define TRANSFORM_COMPONENT(pos)            component_create(transform_create(pos), transform_init, transform_update, transform_draw, transform_destroy, Transform)
#define SPRITE_COMPONENT(filepath)                 component_create(sprite_create(filepath), sprite_init, sprite_update, sprite_draw, sprite_destroy, Sprite)
#define COLLIDER_COMPONENT(tag)             component_create(collider_create(tag), collider_init, collider_update, collider_draw, collider_destroy, Collision)
#define KEYBOARD_COMPONENT                         component_create(keyboard_create(), keyboard_init, keyboard_update, keyboard_draw, keyboard_destroy, KeyBoard)

typedef enum game_state{
    RUNNING,
    NOT_RUNNING
}game_state_t;
manager_t *manager;
int started;
SDL_Renderer *renderer;
SDL_Window *win;
SDL_Event event;
typedef struct game game_t;
struct game{
    game_state_t state;
};

game_t *game_create();

void game_init(const char *title, int posX, int posY, int width, int height);
void game_update(game_t *game);
void game_draw(game_t *game);
void game_eventhandler(game_t *game);
void game_clean(game_t *game);



#endif