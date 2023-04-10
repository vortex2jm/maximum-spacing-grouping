// Espaço m dimensional
// Salvar valores das distâncias numa matriz bidimensional (pode ser um vetor)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "element.h"
#include "util.h"

int main(int argc, char const *argv[])
{
    char *input_file = strdup(argv[1]);
    char *output_file = strdup(argv[3]);

    ElementSet *set = init_set();
    unsigned short dimensions = read_elements(input_file, set);
    print_set(set);
    end_set(set);

    free(input_file);
    free(output_file);
    return 0;
}
