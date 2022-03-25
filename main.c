#include <stdio.h>
#include <ctype.h>
#include <string.h>

void decode(char text[200], char word1[15], char word2[15]); /* recibe texto de entrada, dos palabras del mismo largo y
                                                * archivo en donde se va a escribir la salida (por hacer)*/
void encode(char text[200], char word1[15], char word2[15]);


int main(int argc, char *argv[]) {
    FILE *fpointer;
    char text[200];
    char word1[15];
    char word2[15];

    /* para recuperar el texto de entrada */
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


    return 0;
}


void encode(char text[200], char word1[15], char word2[15]) {  // procedimiento para cifrar texto //
}

void decode(char text[200], char word1[15], char word2[15]) {

}

