// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }
    int a,b;
    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
        
    }
    FILE *output = fopen(argv[2], "a");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    
    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t buffer[HEADER_SIZE];
    fread(buffer, HEADER_SIZE, 1, input);
    fwrite(buffer, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer_16;
    while (fread(&buffer_16, sizeof(int16_t), 1, input))
    {
        printf("%i", buffer_16);
        buffer_16 *= factor;
        printf("%i", buffer_16);

        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
    // Close files
    fclose(input);
    fclose(output);
}
