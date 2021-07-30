#define SOKOL_IMPL
#include "sokol_app.h"
#include "sokol_gfx.h"
#include "sokol_glue.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define GX_IMPL
#include "gx.h"

bool mouse;
int mouse_x;
int mouse_y;

gx_sprite hi;

void init(void) {
    sg_setup(&(sg_desc){
        .context = sapp_sgcontext()
    });
    gx_setup();
    hi = gx_make_sprite("bitmap.png");
}

void frame(void) {
    gx_begin_drawing();
    gx_draw_rect(0, 0, 800, 600, (sg_color){ .4f, .5f, 1.0f, 1.0f } );
    gx_draw_sprite(0, 0, &hi);
    gx_end_drawing();
}

void cleanup(void) {
    gx_shutdown();
    sg_shutdown();
}

static void event(const sapp_event* ev) {
    switch (ev->type) {
        case SAPP_EVENTTYPE_MOUSE_DOWN:
            mouse = 1;
            break;
        case SAPP_EVENTTYPE_MOUSE_UP:
            mouse = 0;
            break;
        case SAPP_EVENTTYPE_MOUSE_MOVE:
            mouse_x = ev->mouse_x;
            mouse_y = ev->mouse_y;
            break;
        default:
            break;
    }
}

sapp_desc sokol_main(int argc, char* argv[]) {
    (void)argc; (void)argv;
    return (sapp_desc){
        .init_cb = init,
        .frame_cb = frame,
        .cleanup_cb = cleanup,
        .event_cb = event,
        .width = 800,
        .height = 600,
        .window_title = "test1",
    };
}
