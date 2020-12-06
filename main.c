#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE* source;
    FILE* final;
    short int buffer_size;
    char* buffer;
    unsigned int i;

    if (argc > 4)
    {
        printf("Poucos argumentos.\n");
        exit(0);
    }

    source = fopen(argv[1], "r");
    final = fopen(argv[2], "a");
    buffer_size = atoi(argv[3]);
    buffer = (char*) malloc(sizeof(char) * buffer_size);

    if (source == NULL)
        printf("Erro ao abrir arquivo de entrada.\n");

    if (final == NULL)
        printf("Erro ao criar arquivo de saida.\n");

    if (buffer_size == 0)
        printf("Tamanho de buffer inválido.\n");

    while (1)
    {
        size_t read = fread((void*) buffer, sizeof (char), buffer_size, source);

        fwrite((void*) buffer, sizeof (char), read, final);

        if (read < buffer_size) {
            break;
        }

    }

    fflush(final);
    fclose(final);
    fclose(source);
    free(buffer);

    return 0;
}
