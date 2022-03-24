#include <stdio.h>

int main(int argc, char *argv[]) {

    FILE *fpointer = fopen("mensaje.txt", "r");

    char text[150];
    fgets(text, 150, fpointer);

    printf("%s", text);

    //printf("La cantidad de argumentos es: %d\n", argc);
    //for (int i = 0; i < argc; ++i)
    //    printf("El argumento %d es %s\n", i, argv[i]);
}

