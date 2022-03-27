#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void encode_decode(char text[200], char word1[15], char word2[15], char arch2[15]); /* recibe texto de entrada, dos palabras del mismo largo y
                                                * archivo en donde se va a escribir la salida (por hacer)*/

void concatenate(char *cadena, char c);


int main(int argc, char *argv[]) {
    FILE *fpointer;
    char text[200];
    char option1[] = {"encode"};
    char option2[] = {"decode"};
    char *word1[15] = {argv[3]};
    char *word2[15] = {argv[4]};

    char *arch1[15] = {argv[1]};
    char *arch2[15] = {argv[5]};

    char *p1; // puntero para recorrer *word1
    char *p2;

    /* verificaciones que todos los argumentos se hayan pasado
     * bien antes de comenzar a llamar a los procedimientos */

    if (argc != 6) {
        printf("error: Debes ingresar 5 argumentos\n");
        return -1;
    }


    if (strcmp(*arch1, *arch2) == 0) {
        perror("Nombre del archivo de salida tiene que ser distinto al de entrada");
        return -1;
    }

    p1 = *word1;
    while (*p1 != '\0') {
        p2 = *word2;
        while (*p2 != '\0') {
            if (*p1 == *p2) {
                perror("error: las palabras clave no pueden contener las mismas letras");
                return -1;
            }
            p2++;
        }
        p1++;
    }

    if (strlen(*word1) != strlen(*word2)) {
        perror("error: las palabras clave deben ser del mismo largo\n");
        return -1;
    }

    fpointer = fopen(argv[1], "r");
    if (fpointer == NULL) {
        perror("Opening file");
        return -1;
    } else {
        fgets(text, 200, fpointer); /* ya tenemos el texto de entrada */
    }
    fclose(fpointer);

    // inicializamos los procedimientos para codificar o decodificar //
    if (strcmp(argv[2],option1) == 0) {
        encode_decode(text, *word1, *word2, *arch2);
    }
    else if (strcmp(argv[2],option2) == 0) {
        encode_decode(text, *word1, *word2, *arch2);
    }
    else {
        perror("El segundo argumento debe ser decode o encode");
        return -1;
    }
    return 0;
}


void encode_decode(char text[200], char word1[15], char word2[15], char arch2[15]) {  // procedimiento para cifrar o descifrar texto //

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
        bool bool_text = false;  /* creamos booleanos para tener un indicador para cuando
                                  * la letra que revisamos es mayúscula */

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

    const char* filename = arch2;
    FILE* output_file = fopen(filename, "w+");
    fwrite(cadena, 1, strlen(cadena), output_file);
    fclose(output_file);
}

void concatenate(char *cadena, char c)
{
    char cadenaTemporal[2];
    cadenaTemporal[0] = c;
    cadenaTemporal[1] = '\0';
    strcat(cadena, cadenaTemporal);
}
