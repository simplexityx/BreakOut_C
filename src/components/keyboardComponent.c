#include "../../includes/keyboardComponent.h"
#include "../../includes/game.h"
#include "../../includes/vector2D.h"
#include "../../includes/transformComponent.h"

void keyboard_init(void *e, void *c){
   
    keyboardComponent_t *k = (keyboardComponent_t*)c;
    k->t = get_component(e, Transform);
    return;
}

void keyboard_update(void *c){
    keyboardComponent_t *k = (keyboardComponent_t*)c;
    
    k->keyboard_state_array = SDL_GetKeyboardState(NULL);
  
    Vector2D_t tmp = Vector2(0, 0);
    if (k->keyboard_state_array[SDL_SCANCODE_A]) {
        tmp.x = - 200;
    }
    if (k->keyboard_state_array[SDL_SCANCODE_D]) {
       tmp.x = 200;
    }

    if (k->keyboard_state_array[SDL_SCANCODE_SPACE]){
        if(started == 0){
            started = 1;
        }
    }
    k->t->speed = tmp;
    return;
}

void keyboard_draw(void *c){
    return;
}


void keyboard_destroy(void *c){

    free(c);
}



keyboardComponent_t *keyboard_create(){
    keyboardComponent_t *k = malloc(sizeof(keyboardComponent_t));
    assert(k != NULL);

    return k;
}

