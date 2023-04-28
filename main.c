#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "graph.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        puts("Wrong number of arguments!");
        exit(EXIT_FAILURE);
    }
    char filePath[strlen(argv[1])];
    strcpy(filePath, argv[1]);
    FILE *inputFile = fopen(filePath, "r");
    if (inputFile == NULL) {
        puts("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(inputFile, 0, SEEK_END);
    int fileLen = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    char buffer[fileLen];
    fread(buffer, sizeof(char), fileLen, inputFile);

    int rows = rowCounter(buffer, fileLen);
    int cols = colCounter(buffer);

    char **matrix = strToMatrix(buffer, rows, cols);

    graphvizConverter(matrix, rows, cols);

    fclose(inputFile);
}


