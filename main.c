#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        puts("Wrong number of arguments!");
        exit(EXIT_FAILURE);
    }
    char inputFilePath[strlen(argv[1])];
    strcpy(inputFilePath, argv[1]);
    char outputFilePath[strlen(argv[2])];
    strcpy(outputFilePath, argv[2]);
    char pngFilePath[strlen(argv[3])];
    strcpy(pngFilePath, argv[3]);
    FILE *inputFile = fopen(inputFilePath, "r");
    if (inputFile == NULL) {
        puts("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(inputFile, 0, SEEK_END);
    int fileLen = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    char buffer[fileLen];
    fread(buffer, sizeof(char), fileLen, inputFile);
    fclose(inputFile);
    int rows = rowCounter(buffer, fileLen);
    int cols = fileLen / rows;
    char **matrix = strToMatrix(buffer, rows, cols);

    graphvizOutput(matrix, rows, cols, outputFilePath, pngFilePath);
}

// Parsing with spaces between nums
// Graph implementation in C
// constructor & destructor
// dfs