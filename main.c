#include <stdio.h>
#include <ctype.h>
#include <string.h>

void decode(char text[200], char word1[15], char word2[15]); /* recibe texto de entrada, dos palabras del mismo largo y
                                                * archivo en donde se va a escribir la salida (por hacer)*/
void encode(char text[200], char word1[15], char word2[15]);



int main(int argc, char *argv[]) {

    FILE *fpointer;
    char text[200];
    char option1[] = {"encode"};
    char option2[] = {"decode"};
    char word1[15];
    char word2[15];

    fpointer = fopen(argv[1], "r");
    if (fpointer == NULL) {
        perror("Opening file");
        return (-1);
    } else {
        fgets(text, 200, fpointer);
    }
    fclose(fpointer);

    /* ya tenemos el texto de entrada */

    if (strcmp(argv[2],option1) == 0) {
        printf("encode\n");
    }
    else if (strcmp(argv[2],option2) == 0) {
        printf("decode\n");
    }
    else {
        perror("Proceso no definido");
    }

    printf("%s", text);
    return 0;
}


void encode(char text[200], char word1[15], char word2[15]) {  // procedimiento para cifrar texto //
}

void decode(char text[200], char word1[15], char word2[15]) {

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

//    return 0;
//USAR DE ESTA PARTE DEL CÓDIGO LO QUE HACE QUE LEA EL ARCHIVO MENSAJE.TXT Y GENERE OTRO ARCHIVO TEXT CON LAS ESPECIFICACIONES DADAS
//}

