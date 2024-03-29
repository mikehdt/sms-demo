#include "../assets2banks.h"
#include "../engine/palettes.h"
#include "../engine/scenes.h"
#include "../engine/sprites.h"
#include "../engine/tilemap.h"
#include "../libs/SMSlib.h"
#include "sphere.h"

int cur_pal = 0;

const unsigned char sphere_palette[] = {
    // 1
    0x06, 0x06, 0x1A, 0x1A,
    0x06, 0x06, 0x1A, 0x1A,
    0x1A, 0x1A, 0x06, 0x06,
    0x1A, 0x1A, 0x06, 0x06,
    // 2
    0x1A, 0x06, 0x06, 0x1A,
    0x1A, 0x06, 0x06, 0x1A,
    0x06, 0x1A, 0x1A, 0x06,
    0x06, 0x1A, 0x1A, 0x06,
    // 3
    0x1A, 0x1A, 0x06, 0x06,
    0x1A, 0x1A, 0x06, 0x06,
    0x06, 0x06, 0x1A, 0x1A,
    0x06, 0x06, 0x1A, 0x1A,
    // 4
    0x06, 0x1A, 0x1A, 0x06,
    0x06, 0x1A, 0x1A, 0x06,
    0x1A, 0x06, 0x06, 0x1A,
    0x1A, 0x06, 0x06, 0x1A,
    // 5
    0x06, 0x06, 0x1A, 0x1A,
    0x06, 0x06, 0x1A, 0x1A,
    0x1A, 0x1A, 0x06, 0x06,
    0x1A, 0x1A, 0x06, 0x06,
    // 6
    0x1A, 0x1A, 0x06, 0x06,
    0x06, 0x06, 0x1A, 0x1A,
    0x06, 0x06, 0x1A, 0x1A,
    0x1A, 0x1A, 0x06, 0x06,
    // 7
    0x1A, 0x1A, 0x06, 0x06,
    0x1A, 0x1A, 0x06, 0x06,
    0x06, 0x06, 0x1A, 0x1A,
    0x06, 0x06, 0x1A, 0x1A,
    // 8
    0x06, 0x06, 0x1A, 0x1A,
    0x1A, 0x1A, 0x06, 0x06,
    0x1A, 0x1A, 0x06, 0x06,
    0x06, 0x06, 0x1A, 0x1A,
    // 9
    0x06, 0x06, 0x1A, 0x1A,
    0x06, 0x06, 0x1A, 0x1A,
    0x1A, 0x1A, 0x06, 0x06,
    0x1A, 0x1A, 0x06, 0x06,
    // 10
    0x06, 0x1A, 0x1A, 0x06,
    0x06, 0x1A, 0x1A, 0x06,
    0x1A, 0x06, 0x06, 0x1A,
    0x1A, 0x06, 0x06, 0x1A,
    // 11
    0x1A, 0x1A, 0x06, 0x06,
    0x1A, 0x1A, 0x06, 0x06,
    0x06, 0x06, 0x1A, 0x1A,
    0x06, 0x06, 0x1A, 0x1A,
    // 12
    0x1A, 0x06, 0x06, 0x1A,
    0x1A, 0x06, 0x06, 0x1A,
    0x06, 0x1A, 0x1A, 0x06,
    0x06, 0x1A, 0x1A, 0x06,
    // 13
    0x06, 0x06, 0x1A, 0x1A,
    0x06, 0x06, 0x1A, 0x1A,
    0x1A, 0x1A, 0x06, 0x06,
    0x1A, 0x1A, 0x06, 0x06,
    // 14
    0x06, 0x06, 0x1A, 0x1A,
    0x1A, 0x1A, 0x06, 0x06,
    0x1A, 0x1A, 0x06, 0x06,
    0x06, 0x06, 0x1A, 0x1A,
    // 15
    0x1A, 0x1A, 0x06, 0x06,
    0x1A, 0x1A, 0x06, 0x06,
    0x06, 0x06, 0x1A, 0x1A,
    0x06, 0x06, 0x1A, 0x1A,
    // 16
    0x1A, 0x1A, 0x06, 0x06,
    0x06, 0x06, 0x1A, 0x1A,
    0x06, 0x06, 0x1A, 0x1A,
    0x1A, 0x1A, 0x06, 0x06};

int last_subset_ptr = -1;

void init_background(void)
{
    // Background
    uint16_t bg_tile = 256 | TILE_USE_SPRITE_PALETTE | TILE_PRIORITY;
    SMS_mapROMBank(blank_tiles_psgcompr_bank);
    clear_tilemap(bg_tile);

    // Sphere
    SMS_mapROMBank(sphere_tiles_psgcompr_bank);
    SMS_loadPSGaidencompressedTiles(sphere_tiles_psgcompr, 0);
    SMS_loadSTMcompressedTileMap(10, 5, sphere_tilemap_stmcompr);

    // Clip background tiles in around the sphere tilemap
    // TL
    SMS_setTileatXY(10, 5, bg_tile);
    SMS_setTileatXY(10, 6, bg_tile);
    SMS_setTileatXY(11, 5, bg_tile);
    SMS_setTileatXY(11, 6, bg_tile);
    // TR
    SMS_setTileatXY(20, 5, bg_tile);
    SMS_setTileatXY(20, 6, bg_tile);
    SMS_setTileatXY(21, 5, bg_tile);
    SMS_setTileatXY(21, 6, bg_tile);
    // BL
    SMS_setTileatXY(10, 15, bg_tile);
    SMS_setTileatXY(10, 16, bg_tile);
    SMS_setTileatXY(11, 15, bg_tile);
    SMS_setTileatXY(11, 16, bg_tile);
    // BR
    SMS_setTileatXY(20, 15, bg_tile);
    SMS_setTileatXY(20, 16, bg_tile);
    SMS_setTileatXY(21, 15, bg_tile);
    SMS_setTileatXY(21, 16, bg_tile);
}

void init_sphere_sprites(void)
{
    SMS_setSpriteMode(SPRITEMODE_ZOOMED);
    SMS_useFirstHalfTilesforSprites(false);
    SMS_initSprites();

    // Clipping sprites
    SMS_mapROMBank(sphere_clip_tiles_psgcompr_bank);
    SMS_loadPSGaidencompressedTiles(sphere_clip_tiles_psgcompr, 256);

    SMS_setSpritePaletteColor(0, 0x10);
    SMS_setSpritePaletteColor(1, 0x10);

    // First row
    SMS_addSprite(12 * 8, 5 * 8, 257);
    SMS_addSprite(14 * 8, 5 * 8, 258);
    SMS_addSprite(16 * 8, 5 * 8, 259);
    SMS_addSprite(18 * 8, 5 * 8, 260);
    // Second Row
    SMS_addSprite(10 * 8, 7 * 8, 261);
    SMS_addSprite(20 * 8, 7 * 8, 262);
    // Third Row
    SMS_addSprite(10 * 8, 9 * 8, 263);
    SMS_addSprite(20 * 8, 9 * 8, 264);
    // Fourth Row
    SMS_addSprite(10 * 8, 11 * 8, 265);
    SMS_addSprite(20 * 8, 11 * 8, 266);
    // Fifth Row
    SMS_addSprite(10 * 8, 13 * 8, 267);
    SMS_addSprite(20 * 8, 13 * 8, 268);
    // Sixth Row
    SMS_addSprite(12 * 8, 15 * 8, 269);
    SMS_addSprite(14 * 8, 15 * 8, 270);
    SMS_addSprite(16 * 8, 15 * 8, 271);
    SMS_addSprite(18 * 8, 15 * 8, 272);

    SMS_copySpritestoSAT();
}

void sphere_init(void)
{
    SMS_displayOff();
    SMS_waitForVBlank();

    init_background();
    init_sphere_sprites();

    SMS_displayOn();
}

void sphere_update(void)
{
    cur_frame++;

    if (cur_frame >= 200)
    {
        next_scene();
    }

    unsigned char temporal_palette[16], i;
    int subset_ptr = cur_pal >> 3;

    if (++cur_pal >= 16 * 8)
    {
        cur_pal = 0;
    }

    // Wait here so as if the pointers match, it'll run too quickly
    SMS_waitForVBlank();

    if (last_subset_ptr == subset_ptr)
        return; // Don't update the palette, it hasn't changed
    else
        last_subset_ptr = subset_ptr;

    for (i = 0; i < 16; i++)
    {
        temporal_palette[i] = sphere_palette[(subset_ptr * 16) + i];
    }

    SMS_loadBGPalette(temporal_palette);
}

void sphere_end(void)
{
    SMS_waitForVBlank();
    SMS_displayOff();

    load_palette(palette_black, PALETTE_BACKGROUND);
    load_blank_tile(0);
    clear_tilemap(0);
    clear_sprites();

    SMS_displayOn();
}
