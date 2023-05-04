#ifndef FLITA_HW2_GRAPH_H
#define FLITA_HW2_GRAPH_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node {
    int number;
    struct Edge *edgeList;
};

struct Edge {
    int source;
    int destination
};

int rowCounter(const char *buffer, int len);

char **strToMatrix(char *buffer, int rows, int cols);

void graphvizOutput(char **matrix, int rows, int cols, char *outputFilePath, char *pngFilePath);

#endif
