#ifndef COLLIDER_COMPONENT_H
#define COLLIDER_COMPONENT_H

#include "headers.h"
typedef struct colliderComponent colliderComponent_t;
struct colliderComponent{
    SDL_Rect col;
    spriteComponent_t *sprite;
    Groups_t tag;
    entities_t *owner;
};

colliderComponent_t *collider_create(Groups_t tag);

void collider_init(void *e, void *c);
void collider_update(void *c);
void collider_draw(void *c);
void collider_destroy(void *c);



#endif