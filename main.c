#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void output_array(Array *a)  // Printing array
{
    for (int i = 0; i < a->size; i++)
    {
        printf("%f\n", a->data[i]);
    }
}

void shift_array(Array *a)  // Shifting values
{
    double num = a->data[0];
    for (int i = 0; i < a->size - 1; i++)
    {
        a->data[i] = a->data[i + 1];
    }
    a->data[a->size - 1] = num;
}

Array *average_adjacent(Array *a)  // Finding the average of the array
{
    Array *newArray = (Array *) malloc(sizeof(Array));  // Declaring new array variable and allocating memory
    newArray->data = (double *) malloc((a->size / 2) * sizeof(double));  // Allocating memory for data
    newArray->size = a->size / 2;  // Setting size

    if (newArray == NULL || newArray->data == NULL)  // Checking memory allocation
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < newArray->size; i++)
    {
        newArray->data[i] = (a->data[2 * i] + a->data[2 * i + 1]) / 2;
    }

    return newArray;
}

int main(int argc, char *argv[])
{
    if (argc != 2)  // Checking user input
    {
        printf("Please enter the size\n");
        exit(1);
    }

    int size = atoi(argv[1]);  // Assigning to the size variable

    if (size <= 0)  // Checking user input
    {
        printf("this size is invalid\n");
        exit(1);
    }

    Array *myArray = (Array *) malloc(sizeof(Array));  // Declaring new array variable and allocating memory
    myArray->data = (double *) malloc(size * sizeof(double));  // Allocating memory for data
    myArray->size = size;  // Setting size

    if (myArray == NULL || myArray->data == NULL)  // Checking memory allocation
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        myArray->data[i] = i + 1;  // Adding values to the array
    }

    output_array(myArray);  // Printing array
    shift_array(myArray);  // Shifting array values
    output_array(myArray);  // Printing updated array
    Array *result = average_adjacent(myArray);  // Finding average
    output_array(result);  // Printing new array

    free(myArray->data);  // Freeing myArray's data
    free(myArray);  // Freeing myArray
    free(result->data);  // Freeing result's data
    free(result);  // Freeing result

    return 0;
}
