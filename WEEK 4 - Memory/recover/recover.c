#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }
    FILE *outptr = NULL;
    BYTE buffer[512];
    int jpeg = 0;
    char filename[8] = {0};
    while (fread(buffer, sizeof(BYTE) * 512, 1, inptr) == 1)
    {
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF &&
            (buffer[3] & 0xF0) == 0xE0)
        {
            if (outptr != NULL)
            {
                fclose(outptr);
            }
            sprintf(filename, "%03d.jpg", jpeg++);
            outptr = fopen(filename, "w");
        }
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE) * 512, 1, outptr);
        }
    }
    if (outptr != NULL)
    {
        fclose(outptr);
    }
    fclose(inptr);

    return 0;
}
