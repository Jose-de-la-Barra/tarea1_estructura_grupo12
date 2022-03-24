//wenactm//
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    printf("La cantidad de argumentos es: %d\n", argc);
    for(int i = 0; i < argc; ++i)
        printf("El argumento %d es %s\n", i, argv[i]);
//HASTA AQUÍ TENEMOS LOS ARGUMENTOS
    //Cómo hacerlo, argv[3] y argv[4] son las palabras claves *revisar en verdad, puede que sean el [2] y [3]*, por lo tanto, lo que se puede hacer es, evaluar las palabras letra por letra
    // y lograr reemplazar las letras de la primera palabra con los de la segunda, letra por letra(lista?????) para así hacer el cambio en el archivo, pero generando otro desde el argv[4]
    FILE *fin = fopen("mensaje.txt", "r");
    FILE *fout = fopen("mensaje_min.txt", "w");
    char c = fgetc(fin);
    while(c != EOF)
    {
        fputc(tolower(c), fout);
        c = fgetc(fin);
    }

    fclose(fin);
    fclose(fout);
    //USAR DE ESTA PARTE DEL CÓDIGO LO QUE HACE QUE LEA EL ARCHIVO MENSAJE.TXT Y GENERE OTRO ARCHIVO TEXT CON LAS ESPECIFICACIONES DADAS
}
//ESTA WEA ES UN POCO INÚTIL
