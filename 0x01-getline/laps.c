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
	while (i < size)
	{

		while (j < k)
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
 * sort_cars - sort cars.
 * @cars: array of cars
 * @laps: array of laps
 * @n: number of cars
 * Return: Void
 */
void sort_cars(int *cars, int *laps, int n)
{
	int tmp;
	int i = n;

	while (i > 0)
	{
		if (cars[i] < cars[i - 1])
		{
			tmp = cars[i - 1];
			cars[i - 1] = cars[i];
			cars[i] = tmp;
			tmp = laps[i - 1];
			laps[i - 1] = laps[i];
			laps[i] = tmp;
		}
		i--;
	}
}
