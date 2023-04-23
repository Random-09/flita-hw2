#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

int main() {
    FILE *inputFile = fopen(INPUT_FILE, "r");
    if (inputFile == NULL) {
        puts("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(inputFile, 0, SEEK_END);
    int fileLen = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    char buffer[fileLen];
    fread(buffer, sizeof(char), fileLen, inputFile);
    int rowsNum = rowCounter(buffer, fileLen);
    int columnsNum = columnCounter(buffer);

    int matrix[rowsNum][columnsNum];

    strToMatrix(*matrix, buffer);

    fclose(inputFile);
}


