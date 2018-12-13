#include "../includes/levelManager.h"
#include <stdio.h>
#include "../includes/game.h"
#include "../includes/vector2D.h"
#include "../includes/transformComponent.h"
#include "../includes/spriteComponent.h"
#include "../includes/headers.h"
#include "../includes/colliderComponent.h"
#include "../includes/keyboardComponent.h"
#define BRICK_START_POINT_X 100
#define BRICK_START_POINT_Y 100

void create_paddle(){

    entities_t *paddle = entities_create();
    add_component(paddle, TRANSFORM_COMPONENT(Vector2(400, 500)));
    add_component(paddle, SPRITE_COMPONENT("./assets/paddle.png"));
    add_component(paddle, KEYBOARD_COMPONENT);
    manager_insert(manager, paddle, PADDLE);
    return;
}

void create_ball(){
    entities_t *ball = entities_create();
    add_component(ball, TRANSFORM_COMPONENT(Vector2(464, 478)));
    add_component(ball, SPRITE_COMPONENT("./assets/ball.png"));
    manager_insert(manager, ball, BALL);
    return;
}

void create_brick(int type, int x, int y){
    entities_t *brick = entities_create();
    add_component(brick, TRANSFORM_COMPONENT(Vector2(x, y)));
    add_component(brick, SPRITE_COMPONENT("./assets/greenbrick.png"));
    add_component(brick, COLLIDER_COMPONENT(BRICKS));
    manager_insert(manager, brick, BRICKS);
}


void level_gen(const char *map){
    FILE *f = fopen(map, "r");
    if(f == NULL){
        printf("couldnt find file exiting");
        return;
    }
    for(int y = 0; y < 3; y++){
        for(int x = 0; x <6; x++){
            int k = fgetc(f);
            k -= 48;
            switch(k){
                case 1:
                    create_brick(1, (x * 64) + BRICK_START_POINT_X, (y * 32) + BRICK_START_POINT_Y);
                    break;
                case 2:

                    break;
            }
        }
    }
    fclose(f);
    create_paddle();
    create_ball();

    return;
}

levelManager_t *levelManager_create(){

    levelManager_t *l = malloc(sizeof(levelManager_t));
    l->level_generator = level_gen;
    return l;
}