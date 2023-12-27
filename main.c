#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

// Verify initializations
void must_init(bool test, const char *description)
{
    if (test)
        return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

const char* get_event_type_name(int event_type)
{
    switch (event_type)
    {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            return "ALLEGRO_EVENT_DISPLAY_CLOSE";
        case ALLEGRO_EVENT_KEY_DOWN:
            return "ALLEGRO_EVENT_KEY_DOWN";
        default:
            return "Unknown Event Type";
    }
}

int main()
{
    ALLEGRO_MONITOR_INFO monitor_info;
    ALLEGRO_DISPLAY* display;
    bool fullscreen = false;

    // Starts Allegro
    must_init(al_init(), "allegro");

    // Set the display to be Windowed inicially
    al_set_new_display_flags(ALLEGRO_WINDOWED);

    // Starts keyboard capture
    must_init(al_install_keyboard(), "keyboard");

    // Get the primary monitor's width and height
    al_get_monitor_info(0, &monitor_info);

    // Starts display
    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    al_set_window_title(display, "Blocks V2");
    must_init(display, "display");

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    // Loop principal do jogo
    while (1) 
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        // Handle display close event
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
            break;

        //printf("%s\n", get_event_type_name(ev.type));

        // Toggle fullscreen on key press (F11)
        if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_F11)
        {
            fullscreen = !fullscreen;

            if (fullscreen)
            {
                // Change display mode to fullscreen
                al_set_new_display_flags(ALLEGRO_FULLSCREEN);
                al_destroy_display(display);
                display = al_create_display(monitor_info.x2 - monitor_info.x1, monitor_info.y2 - monitor_info.y1);

                // Re-register display events
                al_register_event_source(event_queue, al_get_display_event_source(display));  
            }
            else
            {
                // Change display mode to windowed
                al_set_new_display_flags(ALLEGRO_WINDOWED);
                al_destroy_display(display);
                display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);

                // Re-register display events
                al_register_event_source(event_queue, al_get_display_event_source(display));
            }
        }
    }

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;  
}