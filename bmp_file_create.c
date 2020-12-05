#include "bmp_file_create.h"

void createbmp()
{
        FILE *file;
        file = fopen("temp.bmp", "w");

        bmp_file *BMP_image;

        BMP_image->BMPheader.head_signature = 0x424D;
        BMP_image->BMPheader.head_file_size = 0x00000004;
        BMP_image->BMPheader.head_reserved1 = 0x0000;
        BMP_image->BMPheader.head_reserved2 = 0x0000;
        BMP_image->BMPheader.head_file_offset_to_pixcels = 0x0037;

        BMP_image->BMPdib.dib_header_size = 0x0028;
        BMP_image->BMPdib.dib_image_width = 0x0002;
        BMP_image->BMPdib.dib_image_hight = 0x0002;
        BMP_image->BMPdib.dib_planes = 0x01;
        BMP_image->BMPdib.dib_bitperPixcel = 0x01;
        BMP_image->BMPdib.dib_compression = 0x00;
        BMP_image->BMPdib.dib_image_size = 0x0000;
        BMP_image->BMPdib.dib_x_pixpermeter = 0x0000;
        BMP_image->BMPdib.dib_y_pixpermeter = 0x0000;
        BMP_image->BMPdib.dib_colors = 0x02;
        BMP_image->BMPdib.dib_important_colors = 0x00;

        fprintf(file, "%x", BMP_image->BMPheader.head_signature);
        fprintf(file, "%x", BMP_image->BMPheader.head_file_size);
}