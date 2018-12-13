#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H
#include "vector2D.h"
#include <stdlib.h>
typedef struct transformComponent transformComponent_t;
struct transformComponent{
    Vector2D_t pos, speed;
    uint32_t lastUpdate;
};

transformComponent_t *transform_create(Vector2D_t pos);

void transform_init(void *e, void *c);
void transform_update(void *c);
void transform_draw(void *c);
void transform_destroy(void *c);


#endif