#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H
#include <SDL2/SDL.h>
#include "transformComponent.h"
#include "headers.h"
typedef struct spriteComponent spriteComponent_t;
struct spriteComponent{
    SDL_Texture *tex;
    SDL_Rect src, dst;
    transformComponent_t *transform;
};

spriteComponent_t *sprite_create(const char *filepath);

void sprite_init(void *e, void *c);
void sprite_update(void *c);
void sprite_draw(void *c);
void sprite_destroy(void *c);


#endif