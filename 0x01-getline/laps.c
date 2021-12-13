#include "laps.h"
/**
 * race_state - race
 * @id: cars
 * @size: number of cars
 * Return: void
 */
void race_state(int *id, size_t size)
{
	static int cars[SIZE];
	static size_t k;
	bool result = false;
	static int laps[SIZE];
	size_t i = 0, j = 0;

	if (!size)
		return;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (id[i] == cars[j])
			{
				result = true;
				laps[j] += 1;
				break;
			}
		}
		if (result == false)
		{
			cars[k] = id[i];
			sort_cars(cars, laps, k);
			k++;
			printf("Car %d joined the race\n", id[i]);
		}
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
	int aux;
	int i = n;

	while (i > 0)
	{
		if (cars[i] < cars[i - 1])
		{
			aux = cars[i - 1];
			cars[i - 1] = cars[i];
			cars[i] = aux;
			aux = laps[i - 1];
			laps[i - 1] = laps[i];
			laps[i] = aux;
		}
		i--;
	}
}
