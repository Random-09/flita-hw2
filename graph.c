#include "graph.h"


int rowCounter(const char *buffer, int len) {
    int count = 1;
    for (int i = 0; i < len; i++) {
        if (buffer[i] == '\n')
            count++;
    }
    return count;
}

char **strToMatrix(char * buffer, int rows, int cols) {
    char *line = strtok(buffer, "\n");
//    char **matrix = (char **) malloc(sizeof(char *) * rows);
    int i = 0;
    while (line != NULL) {
        printf("%s\n", line);
//        matrix[i] = (char *) malloc(sizeof(char) * cols);
//        for (int j = 0; j < cols; j++)
//            matrix[i][j] = line[j];
        line = strtok(NULL, "\n");
        printf("!%s\n", line);
        i++;
    }
//    return matrix;
}

void graphvizConverter(char **matrix, int rows, int cols) {
    FILE *outputFile = fopen(INPUT_FILE, "r");
    if (outputFile == NULL) {
        puts("Error opening file");
        exit(EXIT_FAILURE);
    }
    fputs("digraph G {", outputFile);
    fputs("\tedge[dir=none]", outputFile);
    for (int i = 0; i < cols; i++) {
        int buffer[2];
        int connectionCounter = 0;
        for (int j = 0; j < rows; j++) {
            if (matrix[i][j] == '1') {
                buffer[connectionCounter] = j;
                connectionCounter++;
            }
        }
        if (connectionCounter == 1)
            buffer[1] = buffer[0];
        fprintf( outputFile, "\ta%d -> a%d\n", buffer[0], buffer[1]);
    }
    fputs("}", outputFile);
    fclose(outputFile);
}














//void graphAnalyzer(char ) {
//    for (int i = 0; i < columns; i++) {
//        int vertices[2];
//        int verticesCounter = 0;
//        for (int j = 0; j < rows; j++) {
//            if (matrix[i][j] == 1){
//                vertices[verticesCounter] = 1;
//                verticesCounter++;
//            }
//        }
//        if (verticesCounter == 1)
//            vertices[1] = vertices[0];
//
//    }
//}