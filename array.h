#ifndef ARRAY_H
#define ARRAY_H

struct _my_array  // Defining structure _my_array
{
    int size;
    double *data;
};
typedef struct _my_array Array;  // Assigning the name Array to the struct

void output_array(Array *a);  // Declaring output_array function
void shift_array(Array *a);  // Declaring shift_array function
Array *average_adjacent(Array *a);  // Declaring average_adjacent function

#endif
