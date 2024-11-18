#include <Python.h>
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

void print_python_int(PyObject *po)
{
    PyVarObject *pvo = (PyVarObject *)po;
    PyLongObject *plo = (PyLongObject *)po;
    ssize_t index, size, is_neg;
    unsigned long result = 0, buffer;
    int shift;

    setbuf(stdout, NULL);

    if (!PyLong_Check(po))
    {
        printf("Invalid Int Object\n");
        return;
    }

    size = pvo->ob_size;
    is_neg = size < 0;
    size = is_neg ? -size : size;

    // Overflow check
    if (size > 3 || (size == 3 && plo->ob_digit[2] > 15))
    {
        printf("C unsigned long int overflow\n");
        return;
    }

    // Reconstruct the number
    for (index = 0; index < size; index++)
    {
        shift = (size - index - 1) * PyLong_SHIFT;
        buffer = ((unsigned long)plo->ob_digit[index]) * (1UL << shift);
        result += buffer;
    }

    // Print the number with a negative sign if needed
    if (is_neg)
        printf("-");
    printf("%lu\n", result);
}
