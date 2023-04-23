#ifndef FLITA_HW2_GRAPH_H
#define FLITA_HW2_GRAPH_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE "../input.txt"
#define OUTPUT_FILE "../output.txt"

int rowCounter(char *buffer, int len);

int columnCounter(char *buffer);

void strToMatrix(int *matrix, char *buffer);

#endif
