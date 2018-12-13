#include "../../includes/spriteComponent.h"
#include "../../includes/textureManager.h"
#include "../../includes/entities.h"

spriteComponent_t *sprite_create(const char *filepath){

    spriteComponent_t *s = malloc(sizeof(spriteComponent_t));
    s->tex = load_texture(filepath);
    if(s->tex == NULL){
        printf("tex not loaded \n");
    }
    return s;
}

void sprite_init(void *e, void *c){
    spriteComponent_t *s = c;
    s->transform = get_component(e, Transform);

    SDL_QueryTexture(s->tex, NULL,NULL,&s->src.w, &s->src.h);
    s->dst.w = s->src.w;
    s->dst.h = s->src.h;
    s->src.x = s->src.y = 0;
    s->dst.x = s->transform->pos.x;
    s->dst.y = s->transform->pos.y;
    return;
}
void sprite_update(void *c){
    spriteComponent_t *s = c;
    s->dst.x = s->transform->pos.x;
    s->dst.y = s->transform->pos.y;    

}
void sprite_draw(void *c){
    spriteComponent_t *s = c;
    draw_texture(s->tex, s->src, s->dst, SDL_FLIP_NONE);
}
void sprite_destroy(void *c){
    spriteComponent_t *s = c;
    SDL_DestroyTexture(s->tex);
    free(s);
}