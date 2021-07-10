#define SOKOL_IMPL
#include "sokol_app.h"
#include "sokol_gfx.h"
#include "sokol_glue.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define GX_IMPL
#include "gx.h"

gx_sprite hi;

void init(void) {
    sg_setup(&(sg_desc){
        .context = sapp_sgcontext()
    });
    gx_setup();
    hi = gx_make_sprite("hi.png");
}

void frame(void) {
    gx_begin_drawing();
    gx_draw_rect(300, 300, 100, 100);
    gx_draw_sprite(400, 500, &hi);
    gx_end_drawing();
}

void cleanup(void) {
    gx_shutdown();
    sg_shutdown();
}

sapp_desc sokol_main(int argc, char* argv[]) {
    (void)argc; (void)argv;
    return (sapp_desc){
        .init_cb = init,
        .frame_cb = frame,
        .cleanup_cb = cleanup,
        .width = 800,
        .height = 600,
        .window_title = "test1",
    };
}
