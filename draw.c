#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "init.h"
#include "draw.h"

void drawMainMenu(Images_t* images) 
{
    al_draw_bitmap(images->MenuBackground, 0, 0, 0);
}

void draw(Images_t* images)
{
    drawMainMenu(images);
            
    al_flip_display();
}

