#ifndef BMP_FILE_CREATE_H_
#define BMP_FILE_CREATE_H_

#include <stdint.h>
#include <stdio.h>

enum
{
    BMP_TYPE_BM = 0x4D42,
    BMP_TYPE_BA = 0x4142,
    BMP_TYPE_CI = 0x4943,
    BMP_TYPE_CP = 0x5043,
    BMP_TYPE_IC = 0x4349,
    BMP_TYPE_PT = 0x5450,
};

enum
{
    BMP_COMP_BI_RGB = 0,
    BMP_COMP_BI_RLE8 = 1,
    BMP_COMP_BI_RLE4 = 2,
    BMP_COMP_BI_BITFIELD = 3,
    BMP_COMP_BI_JPEG = 4,
    BMP_COMP_BI_PNG = 5,
    BMP_COMP_BI_ALPHA = 6,
    BMP_COMP_BI_CMYK = 11,
    BMP_COMP_BI_CMYKRLE8 = 12,
    BMP_COMP_BI_CMYKRLE4 = 13,
};

typedef struct __attribute__((packed)) bitmap_header
{
    uint16_t signature;              // 0x00
    uint32_t file_size;              // 0x02
    uint16_t reserved1;              // 0x06
    uint16_t reserved2;              // 0x08
    uint32_t file_offset_to_pixcels; //0x0A

} bmp_header;

_Static_assert(14 == sizeof(struct bitmap_header), "Header structure doesn't match");

typedef struct __attribute__((packed)) bitmap_dib_header
{
    uint32_t header_size;      //0x0E
    uint32_t image_width;      //0x12
    uint32_t image_hight;      //0x16
    uint16_t planes;           //0x1A
    uint16_t bitperPixcel;     //0x1C
    uint32_t compression;      //0x1E
    uint32_t image_size;       //0x22
    uint32_t x_pixpermeter;    //0x26
    uint32_t y_pixpermeter;    //0x2A
    uint32_t colors;           //0x2E
    uint32_t important_colors; //0x32

} bmp_dib;

_Static_assert(40 == sizeof(struct bitmap_dib_header), "DIB structure doesn't match");

typedef struct
{
    bmp_header header;
    bmp_dib dib_info;
    

} bmp_file_header;

typedef struct 
{
    uint8_t Red;
    uint8_t Green;
    uint8_t Blue;
    
} bmp_pixcel;



void create_bmp_file(FILE bFile);
    
void draw_pixcels(FILE bFile);


#endif