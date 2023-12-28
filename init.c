#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "init.h"

void must_init(bool test, const char *description)
{
    if (test)
        return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

// Funcao que carrega os Backgrounds
void load_backgrounds(Images_t* images)
{
    images->MenuBackground = al_load_bitmap("resources/images/MenuBackground.png");
    must_init(images->MenuBackground, "MenuBackground.png");
}

void images_init(Images_t* images)
{
    load_backgrounds(images);
}

void destroyImages(Images_t* images)
{
    al_destroy_bitmap(images->MenuBackground);
    free(images);
}