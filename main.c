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
    file = fopen("temp.bmp", "wb");

    bmp_file *BMP_image;

    BMP_image->BMPheader.head_signature = HEDER_WIN;
    BMP_image->BMPheader.head_file_size = 0x46;
    BMP_image->BMPheader.head_reserved1 = NOT_RELEVANT;
    BMP_image->BMPheader.head_reserved2 = NOT_RELEVANT;
    BMP_image->BMPheader.head_file_offset_to_pixcels = PIXCEL_OFFSET;

    BMP_image->BMPdib.dib_header_size = INFO_HEADER_SIZE;
    BMP_image->BMPdib.dib_image_width = 0x0002;
    BMP_image->BMPdib.dib_image_hight = 0x0002;
    BMP_image->BMPdib.dib_planes = PLANES;
    BMP_image->BMPdib.dib_bitperPixcel = BIT_PER_PIXCEL;
    BMP_image->BMPdib.dib_compression = FILE_COMPRESSION;
    BMP_image->BMPdib.dib_image_size = 16;
    BMP_image->BMPdib.dib_x_pixpermeter = X_PIX_METER;
    BMP_image->BMPdib.dib_y_pixpermeter = Y_PIX_METER;
    BMP_image->BMPdib.dib_colors = NOT_RELEVANT;
    BMP_image->BMPdib.dib_important_colors = NOT_RELEVANT;

    int header_size = sizeof(BMP_image->BMPheader) + sizeof(BMP_image->BMPdib);
    // int data_size = sizeof(BMP_image->data);
    //   int data_elements = (data_size / sizeof(uint32_t)) - 1;

    //int * ptr = NULL;
    //ptr = &data[0];

    int i = 0;
    while (i <= 3)
    {
        i++;
    }

    {

        // BMP_image->data[0] = 0;
        // ptr= 0xFFFF00FF;
        // ptr++;
    }
    //BMP_image->data[0] = 0xFFFFFFFF;

    if (file != NULL)
    {

        fwrite(BMP_image, sizeof(uint8_t), sizeof(BMP_image->BMPheader) + sizeof(BMP_image->BMPdib), file);
        fwrite(BMP_image->data, sizeof(uint8_t), sizeof(BMP_image->data), file);

        fclose(file);
    }
    return 0;
}
