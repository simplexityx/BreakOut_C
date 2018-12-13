#include "../../includes/colliderComponent.h"
#include "../../includes/entities.h"
#include "../../includes/spriteComponent.h"
colliderComponent_t *collider_create(Groups_t tag){
    colliderComponent_t *c = malloc(sizeof(colliderComponent_t));
    c->tag = tag;
    return c;
}

void collider_init(void *e, void *c){
    colliderComponent_t *col = c;
    col->sprite = get_component(e, Sprite); 
    col->col = col->sprite->dst;
    col->owner = e;
    return;
}
void collider_update(void *c){
    colliderComponent_t *col = c;
    col->col = col->sprite->dst;

}
void collider_draw(void *c){

}
void collider_destroy(void *c){
    free(c);
}