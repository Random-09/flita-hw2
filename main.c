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

    int rows = 4; // rowCounter(buffer, fileLen)
    char *line = strtok(buffer, "\n");
    int cols = (int) strlen(line);

    char **matrix = strToMatrix(buffer, rows, cols);

    graphvizConverter(matrix, rows, cols);

    fclose(inputFile);
}


