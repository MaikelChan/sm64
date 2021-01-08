#ifndef GFX_PC_H
#define GFX_PC_H

#include <stdbool.h>

struct GfxRenderingAPI;
struct GfxWindowManagerAPI;

struct GfxDimensions {
    uint32_t width, height;
    float aspect_ratio;
};

extern struct GfxDimensions gfx_current_dimensions;

#define MAX_BUFFERED_TRIANGLES 256
#define VERTEX_BUFFER_SIZE MAX_BUFFERED_TRIANGLES * 26 * 3 // 3 vertices in a triangle and 26 floats per vtx

#ifdef __cplusplus
extern "C" {
#endif

void gfx_init(struct GfxWindowManagerAPI *wapi, struct GfxRenderingAPI *rapi, const char *game_name, bool start_in_fullscreen);
struct GfxRenderingAPI *gfx_get_current_rendering_api(void);
uint16_t *get_framebuffer();
void gfx_start_frame(void);
void gfx_run(Gfx *commands);
void gfx_end_frame(void);
void gfx_shutdown(void);

#ifdef __cplusplus
}
#endif

#endif
