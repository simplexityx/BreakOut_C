#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H
#include <stdlib.h>

typedef void (*level_gen_t)(const char *);
typedef struct levelManager levelManager_t;
struct levelManager{
    level_gen_t level_generator;
};

levelManager_t *levelManager_create();




#endif