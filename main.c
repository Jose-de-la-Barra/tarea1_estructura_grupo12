#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void encode_decode(char text[200], char word1[15], char word2[15]); /* recibe texto de entrada, dos palabras del mismo largo y
                                                * archivo en donde se va a escribir la salida (por hacer)*/

void concatenate(char *cadena, char c);


int main(int argc, char *argv[]) {
    FILE *fpointer;
    char text[200];
    char option1[] = {"encode"};
    char option2[] = {"decode"};
    char *word1[15] = {argv[3]};
    char *word2[15] = {argv[4]};

    // verificaciones antes de comenzar a llamar a los procedimientos //

    if (strlen(*word1) != strlen(*word2)) {
        perror("error: las palabras claves deben ser del mismo largo\n");
        return 1;
    }


    if (argc < 5 || argc > 5) {
        printf("error: Debes ingresar 5 argumentos\n");
        return 1;
    }

    fpointer = fopen(argv[1], "r");
    if (fpointer == NULL) {
        perror("Opening file");
        return -1;
    } else {
        fgets(text, 200, fpointer);
    }
    fclose(fpointer);

    /* ya tenemos el texto de entrada */

    if (strcmp(argv[2],option1) == 0) {
        encode_decode(text, *word1, *word2);
    }
    else if (strcmp(argv[2],option2) == 0) {
        encode_decode(text, *word1, *word2);
    }
    else {
        perror("Proceso no definido");
        return -1;
    }
    return 0;
}


void encode_decode(char text[200], char word1[15], char word2[15]) {  // procedimiento para cifrar o descifrar texto //

    char *pointer; //puntero que apuntará a cada uno de los caracteres del texto principal
    char *p1;
    char *p2;
    char cadena[200] = "";
    int large_w1 = strlen(word1);

    pointer = text;  // primera letra de la cadena


    while (*pointer != '\0') {
        p1 = word1;
        p2 = word2;
        int cont = 0;
        bool bool_text = false;

        if(*pointer >= 'A' && *pointer <= 'Z') {
            bool_text = true;
        }

        while (*p1 != '\0') {
            bool bool_p1 = false;
            bool bool_p2 = false;

            if(*p1 >= 'A' && *p1 <= 'Z') {
                bool_p1 = true;
            }
            if(*p2 >= 'A' && *p2 <= 'Z') {
                bool_p2 = true;
            }

            // *p1 recorre word1 letra por letra mientras que *pointer recorre letra por letra el texto
            if (tolower(*pointer) != tolower(*p1) && tolower(*pointer) != tolower(*p2)) {
                cont++;
            }
            else {

                if (tolower(*pointer) == tolower(*p1) && tolower(*pointer) != tolower(*p2)) {
                    if (bool_text == true) {  /* si la letra del texto de entrada está en mayúscula, la letra que
                                               * agregamos al texto de salida también tiene que estar en mayúscula */
                        concatenate(cadena, toupper(*p2));
                    }

                    else {
                        if (bool_p2 == true) {
                            concatenate(cadena, toupper(*p2));
                        }
                        else {
                            concatenate(cadena, *p2);
                        }
                    }

                }
                else if (tolower(*pointer) != tolower(*p1) && tolower(*pointer) == tolower(*p2)) {
                    if (bool_text == true) {
                        concatenate(cadena, toupper(*p1));
                    }
                    else {
                        if (bool_p1 == true) {
                            concatenate(cadena, toupper(*p1));
                        }
                        else {
                            concatenate(cadena, *p1);
                        }
                    }

                }
            }


            p1++;
            p2++;

            if (cont == large_w1) {
                concatenate(cadena, *pointer);
            }
        }
        pointer++;
    }
    printf("%s", cadena);
}


void concatenate(char *cadena, char c)
{
    char cadenaTemporal[2];
    cadenaTemporal[0] = c;
    cadenaTemporal[1] = '\0';
    strcat(cadena, cadenaTemporal);
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
