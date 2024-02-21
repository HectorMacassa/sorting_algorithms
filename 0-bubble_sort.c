#include "sort.h"
/**
 * swap - Swaps integers
 * @a: The first integer to be swapped
 * @b: The second int to be swapped
 *
 * Return: No return
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: An array of integers to be sorted
 * @size: Size of the array
 *
 * Return: No return
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool swapped = false;

	if (array == NULL || size < 2)
		return;
	while (swapped == false)
	{
		swapped = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				print_array(array, size);
				swapped = false;
			}
		}
		len--;
	}
}
