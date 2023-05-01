#ifndef element_h
#define element_h

// => Estrutura dos vértices
typedef struct element Element;

// => Instancia um novo vértice
Element *init_element(int id, char *name, double *coordinates);

// => Retorna o ID do vértice
int get_element_id(Element *element);

// => Retorna o nome do vértice
char *get_element_name(Element *element);

// => Retorna as coordenadas do vértice
double *get_element_coordinates(Element *element);

// => Imprime o vértice no arquivo de saída
void print_element(Element *element, FILE *file);

// => Libera a memória alocada para o vértice
void end_element(Element *element);

#endif
