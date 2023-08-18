#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    BYTE buffer[512];
    int bytes_read, count = 0;
    char filename[8];

    // Open memory card file

    FILE *f = fopen(argv[1], "r");
    FILE *img = NULL;

    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Check that input_file is valid
    if (f == NULL)
    {
        printf("./recover card.raw\n");
        return 1;
    }

    // repeat until end of card
    while (true)
    {
        // read 512 bytes into a buffer
        bytes_read = fread(buffer, sizeof(BYTE), 512, f);

        // if start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if first JPEG
            if (count == 0)
            {
                // open a new JPEG
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), bytes_read, img);
                count++;
            }
            // if not first JPEG
            else
            {
                // close previous JPEG
                fclose(img);

                // open a new JPEG
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), bytes_read, img);
                count++;
            }
        }

        // else if already found JPEG
        else if (count != 0)
        {
            // keep writing to the same JPEG
            fwrite(buffer, sizeof(BYTE), bytes_read, img);
            if (bytes_read == 0)
            {
                fclose(img);
                fclose(f);
                return 0;
            }
        }
    }
    fclose(img);
    fclose(f);
    // else
// if already found JPEG
    // keep writing to the same JPEG
    // if end of file
    // close file
    // close card
// success
}