#include <stdio.h>
#include "util.h"
#include <string.h>

int get_lines_amount(FILE *file)
{
    int amount = 0;
    for (char c = fgetc(file); c != EOF; c = fgetc(file))
    {
        if (c == '\n')
        {
            amount++;
        }
    }
    fseek(file, 0, SEEK_SET);
    return amount;
}

short get_dimensions(FILE *file)
{
    char line[2000];
    fscanf(file, "%[^\n]\n", line);
    char *tk = strtok(line, ",");
    short count = 0;
    while (tk != NULL)
    {
        count++;
        tk = strtok(NULL, ",");
    }
    fseek(file, 0, SEEK_SET);
    return count - 1;
}
