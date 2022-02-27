#include "sintab.h"

// Let he who is without sin cast the first int8_t
int8_t sintab[256] = {
    0, 3, 6, 9, 12, 15, 18, 21,
    24, 27, 30, 33, 36, 39, 42, 45,
    48, 51, 54, 57, 59, 62, 65, 67,
    70, 73, 75, 78, 80, 82, 85, 87,
    89, 91, 94, 96, 98, 100, 102, 103,
    105, 107, 108, 110, 112, 113, 114, 116,
    117, 118, 119, 120, 121, 122, 123, 123,
    124, 125, 125, 126, 126, 126, 126, 126,
    127, 126, 126, 126, 126, 126, 125, 125,
    124, 123, 123, 122, 121, 120, 119, 118,
    117, 116, 114, 113, 112, 110, 108, 107,
    105, 103, 102, 100, 98, 96, 94, 91,
    89, 87, 85, 82, 80, 78, 75, 73,
    70, 67, 65, 62, 59, 57, 54, 51,
    48, 45, 42, 39, 36, 33, 30, 27,
    24, 21, 18, 15, 12, 9, 6, 3,
    0, -3, -6, -9, -12, -15, -18, -21,
    -24, -27, -30, -33, -36, -39, -42, -45,
    -48, -51, -54, -57, -59, -62, -65, -67,
    -70, -73, -75, -78, -80, -82, -85, -87,
    -89, -91, -94, -96, -98, -100, -102, -103,
    -105, -107, -108, -110, -112, -113, -114, -116,
    -117, -118, -119, -120, -121, -122, -123, -123,
    -124, -125, -125, -126, -126, -126, -126, -126,
    -127, -126, -126, -126, -126, -126, -125, -125,
    -124, -123, -123, -122, -121, -120, -119, -118,
    -117, -116, -114, -113, -112, -110, -108, -107,
    -105, -103, -102, -100, -98, -96, -94, -91,
    -89, -87, -85, -82, -80, -78, -75, -73,
    -70, -67, -65, -62, -59, -57, -54, -51,
    -48, -45, -42, -39, -36, -33, -30, -27,
    -24, -21, -18, -15, -12, -9, -6, -3};

// Neater unsigned version
uint8_t usintab[256] = {
    0x80, 0x83, 0x86, 0x89, 0x8C, 0x90, 0x93, 0x96,
    0x99, 0x9C, 0x9F, 0xA2, 0xA5, 0xA8, 0xAB, 0xAE,
    0xB1, 0xB3, 0xB6, 0xB9, 0xBC, 0xBF, 0xC1, 0xC4,
    0xC7, 0xC9, 0xCC, 0xCE, 0xD1, 0xD3, 0xD5, 0xD8,
    0xDA, 0xDC, 0xDE, 0xE0, 0xE2, 0xE4, 0xE6, 0xE8,
    0xEA, 0xEB, 0xED, 0xEF, 0xF0, 0xF1, 0xF3, 0xF4,
    0xF5, 0xF6, 0xF8, 0xF9, 0xFA, 0xFA, 0xFB, 0xFC,
    0xFD, 0xFD, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFD,
    0xFD, 0xFC, 0xFB, 0xFA, 0xFA, 0xF9, 0xF8, 0xF6,
    0xF5, 0xF4, 0xF3, 0xF1, 0xF0, 0xEF, 0xED, 0xEB,
    0xEA, 0xE8, 0xE6, 0xE4, 0xE2, 0xE0, 0xDE, 0xDC,
    0xDA, 0xD8, 0xD5, 0xD3, 0xD1, 0xCE, 0xCC, 0xC9,
    0xC7, 0xC4, 0xC1, 0xBF, 0xBC, 0xB9, 0xB6, 0xB3,
    0xB1, 0xAE, 0xAB, 0xA8, 0xA5, 0xA2, 0x9F, 0x9C,
    0x99, 0x96, 0x93, 0x90, 0x8C, 0x89, 0x86, 0x83,
    0x80, 0x7D, 0x7A, 0x77, 0x74, 0x70, 0x6D, 0x6A,
    0x67, 0x64, 0x61, 0x5E, 0x5B, 0x58, 0x55, 0x52,
    0x4F, 0x4D, 0x4A, 0x47, 0x44, 0x41, 0x3F, 0x3C,
    0x39, 0x37, 0x34, 0x32, 0x2F, 0x2D, 0x2B, 0x28,
    0x26, 0x24, 0x22, 0x20, 0x1E, 0x1C, 0x1A, 0x18,
    0x16, 0x15, 0x13, 0x11, 0x10, 0x0F, 0x0D, 0x0C,
    0x0B, 0x0A, 0x08, 0x07, 0x06, 0x06, 0x05, 0x04,
    0x03, 0x03, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x03,
    0x03, 0x04, 0x05, 0x06, 0x06, 0x07, 0x08, 0x0A,
    0x0B, 0x0C, 0x0D, 0x0F, 0x10, 0x11, 0x13, 0x15,
    0x16, 0x18, 0x1A, 0x1C, 0x1E, 0x20, 0x22, 0x24,
    0x26, 0x28, 0x2B, 0x2D, 0x2F, 0x32, 0x34, 0x37,
    0x39, 0x3C, 0x3F, 0x41, 0x44, 0x47, 0x4A, 0x4D,
    0x4F, 0x52, 0x55, 0x58, 0x5B, 0x5E, 0x61, 0x64,
    0x67, 0x6A, 0x6D, 0x70, 0x74, 0x77, 0x7A, 0x7D};
