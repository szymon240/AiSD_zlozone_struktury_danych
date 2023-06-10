#include "array.h"

void create_random_array(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = i;
	}
	std::random_shuffle(&array[0], &array[size - 1]);
}
