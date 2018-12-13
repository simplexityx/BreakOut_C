#include "../includes/game.h"

game_t *game;
int main(){

    game = game_create();
    game_init("breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);
    while(game->state == RUNNING){

        game_eventhandler(game);
        game_update(game);
        game_draw(game);

    }
    game_clean(game);
    return 0;
}