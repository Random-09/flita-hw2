#include "graph.h"


int rowCounter(char *buffer, int len) {
    int count = 1;
    for (int i = 0; i < len; i++) {
        if (buffer[i] == '\n')
            count++;
    }
    return count;
}

int columnCounter(char *buffer) {
    int count = 0;
    int i = 0;
    while (buffer[i] != '\n') {
        if (isdigit(buffer[i]))
            count++;
        i++;
    }
    return count;
}

void strToMatrix(int *matrix, char *buffer) {
    char *rows[4];                                        // [rowsNum]
    char *line = strtok(buffer, "\n");
    int i = 0;
    int j = 0;
    while (line != NULL) {
        printf("%s\n", line);
        rows[i] = line;
        line = strtok(NULL, "\n");              // <---- Double while loop
        i++;
    }
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