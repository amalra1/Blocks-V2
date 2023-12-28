#ifndef __INIT__
#define __INIT__

/*
    Library made for initialization functions
    Pedro Amaral Chapelin
*/

// Verify initializations
void must_init(bool test, const char *description);

// Images initialization
void images_init(Images_t* images);

// Free all the images
void destroyImages(Images_t* images);

#endif