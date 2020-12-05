#include <stdio.h>
#include "bmp_file_create.h"

#define HEDER_WIN 0x4D42    // "BM" - Magic Number
#define PIXCEL_OFFSET 56    // 0x36 - Od bajtu 56 zaczynaja sie dane obrazu
#define INFO_HEADER_SIZE 40 // 0x28 - 40 bajtow zajmuje header DIB
#define BIT_PER_PIXCEL 24   // 0x18 - 24bitowy format obrazy R + G + B + RES;
#define FILE_COMPRESSION 0
#define PLANES 1
#define NOT_RELEVANT 0

#define X_PIX_METER 0x0EC4
#define Y_PIX_METER 0x0EC4

static int write_word(FILE *fp, unsigned short w)
{
    putc(w, fp);
    return (putc(w >> 8, fp));
}

static int write_dword(FILE *fp, unsigned int dw)
{
    putc(dw, fp);

    putc(dw >> 8, fp);
    putc(dw >> 16, fp);
    return (putc(dw >> 24, fp));
}

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
    BMP_image->BMPdib.dib_x_pixpermeter = NOT_RELEVANT;
    BMP_image->BMPdib.dib_y_pixpermeter = NOT_RELEVANT;
    BMP_image->BMPdib.dib_colors = NOT_RELEVANT;
    BMP_image->BMPdib.dib_important_colors = NOT_RELEVANT;

    int header_size = sizeof(BMP_image->BMPheader) + sizeof(BMP_image->BMPdib)));
    int data_size = sizeof(BMP_image->data);
    int data_elements = data_size/sizeof(uint32_t);

    for (int i = 0; i < data_elements; i++)
    {
        
    }

    BMP_image->data[0] = 0xFF0000FF;
    BMP_image->data[1] = 0x0000FFFF;
    BMP_image->data[2] = 0x00FF0000;
    BMP_image->data[3] = 0x000000FF;
 
    if (file != NULL)
    {

        fwrite(BMP_image, sizeof(uint8_t), header_size, file);
        fwrite(BMP_image->data, sizeof(uint8_t), data_size, file);

        fclose(file);
    }
    return 0;
}
