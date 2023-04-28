#ifndef FLITA_HW2_GRAPH_H
#define FLITA_HW2_GRAPH_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE "../input.txt"
#define OUTPUT_FILE "../output.dot"

int rowCounter(const char *buffer, int len);

char **strToMatrix(char *buffer, int rows, int cols);

void printMatrix(char **matrix);

void graphvizConverter(char **matrix, int rows, int cols);

#endif
