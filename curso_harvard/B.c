#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK_SIZE 512
bool check(uint8_t block[])
{
    bool checker = true;
    if (block[0] != 0xff || block[1] != 0xd8 || block[2] != 0xff)
        checker = false;
    if (block[3] > 0xef || block[3] < 0xe0)
        checker = false;
    return checker;
}

int main(int argc, char *argv[])
{
    char ent[30];
    scanf("%s", ent);
    // if (argc != 2)
    // {
    //     printf("asd");
    //     return 1;
    // }
    FILE *input;
    input = fopen(ent, "r");
    if (input == NULL)
    {
        printf("Error");
        return 1;
    }
    uint8_t block[BLOCK_SIZE];
    FILE *output = NULL;
    int counter = -1;
    char name[] = "xxx.jpg";
    bool open = false;
    while (fread(block, sizeof(uint8_t), BLOCK_SIZE, input))
    {
        if (check(block))
        {
            counter++;
            name[0] = (counter / 100) + '0';
            name[1] = counter / 10 + '0';
            name[2] = counter / 1 + '0';
            if (open)
                fclose(output);
            output = fopen(name, "w");
            open = true;
        }
        if (open)
        {
            fwrite(block, sizeof(uint8_t), BLOCK_SIZE, output);
        }
    }
    fclose(input);
}
