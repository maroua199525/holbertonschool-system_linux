#include "laps.h"

static Car *cars;

/**
 * race_state - Keep track of the number of laps made by several cars.
 * @id: Array of car identifiers.
 * @size: Size of the id array.
 */
void race_state(int *id, size_t size)
{
    size_t i;
    Car *current;

    if (id == NULL || size == 0)
    {
        freeCars();
        return;
    }

    for (i = 0; i < size; i++)
    {
        updateLaps(id[i]);
    }

    /* Print state of the race */
    printf("Race state:\n");
    current = cars;
    while (current != NULL)
    {
        printf("Car %d [%d laps]\n", current->id, current->laps);
        current = current->next;
    }
}

/**
 * createCar - Create a new car.
 * @id: Car identifier.
 *
 * Return: 0 on success, 1 on failure.
 */
int createCar(int id)
{
    Car *new, *current, *prev;

    new = malloc(sizeof(Car));
    if (new == NULL)
        return (1);
    new->id = id;
    new->laps = 0;
    new->next = NULL;

    if (cars == NULL || cars->id > id)
    {
        new->next = cars;
        cars = new;
    }
    else
    {
        current = cars;
        prev = NULL;
        while (current != NULL && current->id < id)
        {
            prev = current;
            current = current->next;
        }
        new->next = current;
        if (prev != NULL)
            prev->next = new;
    }

    /* Print new car joins the race */
    printf("Car %d joined the race\n", id);
    return (0);
}

/**
 * freeCars - Free all cars.
 */
void freeCars(void)
{
    Car *tmp;

    while (cars)
    {
        tmp = cars;
        cars = cars->next;
        free(tmp);
    }
}

/**
 * updateLaps - Update the number of laps of a car.
 * @id: Car identifier.
 */
void updateLaps(int id)
{
    Car *tmp = cars;
    int exists;

    while (tmp)
    {
		exists = 0;
        if (tmp->id == id)
        {
            tmp->laps += 1;
            exists = 1;
            break;
        }
        tmp = tmp->next;
    }

    if (!exists)
    {
        createCar(id);
    }
}
