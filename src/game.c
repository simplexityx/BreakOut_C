#include "../includes/game.h"
#include "../includes/manager.h"
#include "../includes/levelManager.h"
#include "../includes/transformComponent.h"
levelManager_t *level;
game_t *game_create(){


    game_t *g = malloc(sizeof(game_t));
    g->state = RUNNING;
    started = 0;
    return g;
}

void game_init(const char *title, int posX, int posY, int width, int height){
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        win = SDL_CreateWindow(title, posX, posY, width, height, 0);
        renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);
        if(renderer == NULL){
            printf("renderer failed rip");
        }
        SDL_SetRenderDrawColor(renderer, 250, 200, 0, 0);    

    }
    manager = manager_create();
    level = levelManager_create();
    level->level_generator("./maps/map1.txt");

    return;
}


void game_update(game_t *game){
    for(entities_t *paddle = get_group(manager, PADDLE); paddle != NULL; paddle = paddle->next){
        paddle->update(paddle);
    }

    for(entities_t *ball = get_group(manager, BALL); ball != NULL; ball = ball->next){
        ball->update(ball);
        if(started == 1){
            transformComponent_t *t = get_component(ball, Transform);
            t->speed.x = 200;
            t->speed.y = -200;
        }
    }
    for(entities_t *bricks = get_group(manager, BRICKS); bricks != NULL; bricks = bricks->next){
        bricks->update(bricks);
    }

}
void game_draw(game_t *game){
    SDL_RenderClear(renderer);
    manager_draw(manager, BRICKS);
    manager_draw(manager, PADDLE);
    manager_draw(manager, BALL);
    SDL_RenderPresent(renderer);
}
void game_eventhandler(game_t *game){

    if(SDL_PollEvent(&event)){

        switch(event.type){
            case SDL_QUIT:
                game->state = NOT_RUNNING;
                break;
            
        }
    }
    return;
}
void game_clean(game_t *game){

    destroy_manager(manager);
    free(game);
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}