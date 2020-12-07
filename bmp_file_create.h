#ifndef BMP_FILE_CREATE_H_
#define BMP_FILE_CREATE_H_

#include <stdint.h>
#include <stdio.h>


typedef struct __attribute__((packed)) bitmap_header
{
    uint16_t head_signature;              // 0x00
    uint32_t head_file_size;              // 0x02
    uint16_t head_reserved1;              // 0x06
    uint16_t head_reserved2;              // 0x08
    uint32_t head_file_offset_to_pixcels; //0x0A

} bmp_header;

typedef struct __attribute__((packed)) bitmap_dib_header
{
    uint32_t dib_header_size;      //0x0E
    uint32_t dib_image_width;      //0x12
    uint32_t dib_image_hight;      //0x16
    uint16_t dib_planes;           //0x1A
    uint16_t dib_bitperPixcel;     //0x1C
    uint32_t dib_compression;      //0x1E
    uint32_t dib_image_size;       //0x22
    uint32_t dib_x_pixpermeter;    //0x26
    uint32_t dib_y_pixpermeter;    //0x2A
    uint32_t dib_colors;           //0x2E
    uint32_t dib_important_colors; //0x32

} bmp_dib;

typedef struct
{
    bmp_header BMPheader;
    bmp_dib BMPdib;
    uint32_t *data;
    
} bmp_file;


void createbmp();


#endif