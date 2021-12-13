#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/************ MACROS **********/

#define SIZE 1024

/********** function *********/

void swap_number(int x, int y);
void race_state(int *id, size_t size);
void sort_cars(int *cars, int *laps, int n);

#endif
