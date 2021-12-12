#include "laps.h"
/**
 * race_state - race
 * @id: cars
 * @size: number of cars
 * Return: always 0.
 */
void race_state(int *id, size_t size)
{
	static int cars[SIZE];
	static size_t k;
	bool result = false;
    static int laps[SIZE];
	size_t i = 0, j = 0;

	if (size == 0)
		free(id);
	while(i < size)
	{

		while(j < k)
		{
			if (cars[j] == id[i])
			{
				result = true;
				laps[j] = laps[j] + 1;
				break;
			}
            j++;
		}
		if (result == false)
		{
			cars[k] = id[i];
			sort_cars(cars, laps, k);
			k++;
			printf("Car %d joined the race\n", id[i]);
		}
        i++;
	}
	printf("Race state:\n");
	for (j = 0; j < k; j++)
	{
		printf("Car %d [%d laps]\n", cars[j], laps[j]);
	}
}

/**
 * swap_number -swao two integer
 * @x: integer
 * @y: integer
 * Return: Void
 */
void swap_number(int x, int y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

/**
 * sort_cars - sort cars.
 * @cars: array of cars
 * @laps: array of laps
 * @n: number of cars
 * Return: Void
 */
void sort_cars(int *cars, int *laps, int k)
{
	//int tmp;
	int x;

	for (x = k; x > 0; x--)
	{
		if (cars[x] < cars[x - 1])
		{
			swap_number(cars[x], cars[x - 1]);
			swap_number(laps[x], laps[x - 1]);
		}
	}
}
