#include "graph.h"

int rowCounter(const char *buffer, int len) {
    int count = 1;
    for (int i = 0; i < len; i++) {
        if (buffer[i] == '\n')
            count++;
    }
    return count;
}

char **strToMatrix(char *buffer, int rows, int cols) {
    char *line = strtok(buffer, "\n");
    char **matrix = (char **) malloc(sizeof(char *) * rows);
    int i = 0;
    while (line != NULL) {
        matrix[i] = (char *) malloc(sizeof(char) * cols);
        for (int j = 0; j < cols; j++)
            matrix[i][j] = line[j];
        line = strtok(NULL, "\n");
        i++;
    }
    return matrix;
}

void **freeMatrix() {}


void graphvizOutput(char **matrix, int rows, int cols, char *outputFilePath, char *pngFilePath) {
    FILE *outputFile = fopen(outputFilePath, "w");
    if (outputFile == NULL) {
        puts("Error opening file");
        exit(EXIT_FAILURE);
    }
    fputs("digraph G {\n", outputFile);
    fputs("\tedge[dir=none]\n", outputFile);
    printf("%d %d", rows, cols);
    for (int i = 0; i < cols; i++) {
        int buffer[2];
        int connectionCounter = 0;
        for (int j = 0; j < rows; j++) {
            if (matrix[j][i] == '1') {
                buffer[connectionCounter] = j;
                connectionCounter++;
            } else if (matrix[j][i] == '0') {
                fprintf(outputFile, "\ta%d\n", j);
            }
        }
        if (connectionCounter > 0) {
            if (connectionCounter == 1)
                buffer[1] = buffer[0];
            fprintf(outputFile, "\ta%d -> a%d\n", buffer[0], buffer[1]);
        }
    }
    fputs("}", outputFile);
    fclose(outputFile);
    char str[50];
    sprintf(str, "dot -Tpng %s -o %s", outputFilePath, pngFilePath);
    system(str);
}