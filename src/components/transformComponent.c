#include "../../includes/transformComponent.h"
#include <SDL2/SDL.h>
transformComponent_t *transform_create(Vector2D_t pos){

    transformComponent_t *t = malloc(sizeof(transformComponent_t));
    t->lastUpdate = SDL_GetTicks();
    t->pos = pos;
    t->speed = Vector2(0,0);
    return t;
}

void transform_init(void *e, void *c){

}
void transform_update(void *c){
    transformComponent_t *t = c;
    unsigned long currentTime = SDL_GetTicks();
    unsigned long deltaTime = currentTime - t->lastUpdate;
    t->pos.x += t->speed.x *(deltaTime / 1000.0f);
    t->pos.y += t->speed.y *(deltaTime / 1000.0f);
    t->lastUpdate = currentTime;
}

void transform_draw(void *c){

}
void transform_destroy(void *c){
    free(c);
}