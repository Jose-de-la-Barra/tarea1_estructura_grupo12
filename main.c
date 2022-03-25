#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    /* para recuperar el texto de entrada */
    FILE *fpointer;

    char text[200];
    char option[15];
    char word1[15];
    char word2[15];

    fpointer = fopen(argv[1] , "r");
    if(fpointer == NULL) {
        perror("Error opening file");
        return(-1);
    }
    else {
        fgets(text, 200, fpointer);
    }
    fclose(fpointer);
    /* ya tenemos el texto de entrada */
    option = argv[2];
    if (option == "encode") {
        printf("%s", option);
    }
    if (option == "decode") {
        printf("%s", option);
    }
    else {
        perror("Error proceso no definido");
    }


    /* ya tenemos el texto de entrada */


    return 0;
}



//int main(int argc, char *argv[]) {

//Cómo hacerlo, argv[3] y argv[4] son las palabras claves *revisar en verdad, puede que sean el [2] y [3]*, por lo tanto, lo que se puede hacer es, evaluar las palabras letra por letra
// y lograr reemplazar las letras de la primera palabra con los de la segunda, letra por letra(lista?????) para así hacer el cambio en el archivo, pero generando otro desde el argv[4]
//    FILE *fin = fopen("mensaje.txt", "r");
//    FILE *fout = fopen("mensaje_min.txt", "w");
//    int c = fgetc(fin);
//    while(c != EOF)
//    {
//        fputc(tolower(c), fout);
//        c = fgetc(fin);
//    }

//    fclose(fin);
//    fclose(fout);

//    return 0;
//USAR DE ESTA PARTE DEL CÓDIGO LO QUE HACE QUE LEA EL ARCHIVO MENSAJE.TXT Y GENERE OTRO ARCHIVO TEXT CON LAS ESPECIFICACIONES DADAS
//}
