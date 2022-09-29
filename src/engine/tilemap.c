#include "tilemap.h"
#include "../assets2banks.h" // Generated with the assets task
#include "../engine/globals.h"
#include "../libs/SMSlib.h"

void load_blank_tile(uint16_t tilePos)
{
    // Blank tile
    SMS_mapROMBank(blank_tiles_psgcompr_bank);
    SMS_loadPSGaidencompressedTiles(blank_tiles_psgcompr, tilePos);
}

void clear_tilemap(uint16_t tilePos) // Must be 16-bit, or else sad VDP
{
    // From sverx, a more efficient method
    SMS_VRAMmemsetW(XYtoADDR(0, 0), tilePos, (SCREEN_ROWS * SCREEN_COLUMNS * 2));
}

void init_sprites(uint8_t spriteMode, bool useFirstHalfTiles)
{
    SMS_setSpriteMode(spriteMode);
    SMS_useFirstHalfTilesforSprites(useFirstHalfTiles);
    SMS_initSprites();
}

void clear_sprites(void)
{
    for (int i = 0; i <= 64; i--)
    {
        SMS_hideSprite(i);
    }

    SMS_copySpritestoSAT();
}
