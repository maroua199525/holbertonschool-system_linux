#include "laps.h"
#include <stdio.h>
#include <stdlib.h>

static Car *cars;

/**
 * race_state - Keep track of the number of laps made by several cars.
 * @id: Array of car identifiers.
 * @size: Size of the id array.
 */
void race_state(int *id, size_t size)
{
    size_t i;

    if (id == NULL || size == 0)
    {
        freeCars();
        return;
    }

    for (i = 0; i < size; i++)
    {
        updateLaps(id[i]);
    }

    /* Print state of race */
    printf("Race state:\n");
    printCars();
}

/**
 * updateLaps - Update the number of laps of a car or create a new car.
 * @id: Car identifier.
 */
void updateLaps(int id)
{
    Car *current = cars;
    int found = 0;

    while (current != NULL)
    {
        if (current->id == id)
        {
            current->laps++;
            found = 1;
            break;
        }
        current = current->next;
    }

    if (!found)
    {
        createCar(id);
    }
}

/**
 * createCar - Create a new car.
 * @id: Car identifier.
 */
void createCar(int id)
{
    Car *newCar = malloc(sizeof(Car));
    Car *current;

    if (newCar == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    newCar->id = id;
    newCar->laps = 0;
    newCar->next = NULL;

    if (cars == NULL || id < cars->id)
    {
        newCar->next = cars;
        cars = newCar;
    }
    else
    {
        current = cars;

        while (current->next != NULL && current->next->id < id)
        {
            current = current->next;
        }
        newCar->next = current->next;
        current->next = newCar;
    }

    printf("Car %d joined the race\n", id);
}

/**
 * freeCars - Free all cars.
 */
void freeCars(void)
{
    Car *tmp;

    while (cars != NULL)
    {
        tmp = cars;
        cars = cars->next;
        free(tmp);
    }
}

/**
 * printCars - Print all cars.
 */
void printCars(void)
{
    Car *tmp = cars;

    while (tmp)
    {
        printf("Car %d [%d laps]\n", tmp->id, tmp->laps);
        tmp = tmp->next;
    }
}
