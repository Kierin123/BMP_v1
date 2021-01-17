
#include <stdio.h>
#include <stdlib.h>
#include "bmp_file_create.h"

#define HEDER_WIN 0x4D42    // "BM" - Magic Number
#define PIXCEL_OFFSET 54    // 0x36 - Od bajtu 56 zaczynaja sie dane obrazu
#define INFO_HEADER_SIZE 40 // 0x28 - 40 bajtow zajmuje header DIB
#define BIT_PER_PIXCEL 24   // 0x18 - 24bitowy format obrazy R + G + B + RES;
#define FILE_COMPRESSION 0
#define PLANES 1
#define NOT_RELEVANT 0

#define X_PIX_METER 0x0EC4
#define Y_PIX_METER 0x0EC4

int main(void)
{
    FILE *file;
    file = fopen("temp.bmp", "wa");

     bmp_file_header BMP_image = {0};

    BMP_image.header.signature = HEDER_WIN;
    BMP_image.header.file_size = 0x46;
    BMP_image.header.reserved1 = NOT_RELEVANT;
    BMP_image.header.reserved2 = NOT_RELEVANT;
    BMP_image.header.file_offset_to_pixcels = PIXCEL_OFFSET;


    BMP_image.dib_info.header_size = INFO_HEADER_SIZE;
    BMP_image.dib_info.image_width = 0x0002;
    BMP_image.dib_info.image_hight = 0x0002;
    BMP_image.dib_info.planes = PLANES;
    BMP_image.dib_info.bitperPixcel = BIT_PER_PIXCEL;
    BMP_image.dib_info.compression = FILE_COMPRESSION;
    BMP_image.dib_info.image_size = 16;
    BMP_image.dib_info.x_pixpermeter = X_PIX_METER;
    BMP_image.dib_info.y_pixpermeter = Y_PIX_METER;
    BMP_image.dib_info.colors = NOT_RELEVANT;
    BMP_image.dib_info.important_colors = NOT_RELEVANT;
  
   // int header_size = sizeof(BMP_image.header) + sizeof(BMP_image.dib_info);
    // int data_size = sizeof(BMP_image->data);
    // int data_elements = (data_size / sizeof(uint32_t)) - 1;

//    for (uint32_t i = 0; i <= 3; i++)
//    {
//      BMP_image.data[i] = 0x00FFAABB +(i * 1423U);
//    }

  
    BMP_image.data[0] = 0x00000000;
    BMP_image.data[1] = 0x00000000;
    BMP_image.data[2] = 0x00000000;
    BMP_image.data[3] = 0xFF008000;


     
    if (file != NULL)
    {
        fwrite(&BMP_image, sizeof(uint8_t), (sizeof(BMP_image.header) + sizeof(BMP_image.dib_info)), file);
        fwrite(&BMP_image.data, sizeof(uint8_t), (sizeof(BMP_image.data)), file);
    }
    

    return 0;
}
