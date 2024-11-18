#include <Python.h>
#include <stdio.h>
#include <stdlib.h>

void print_python_int(PyObject *p)
{
    PyLongObject *long_object;
    ssize_t i, size, is_neg;
    unsigned long result = 0;

    setbuf(stdout, NULL);

    if (!PyLong_Check(p))
    {
        printf("Invalid Int Object\n");
        return;
    }

    long_object = (PyLongObject *)p;
    size = long_object->ob_base.ob_size;
    is_neg = size < 0;
    size = is_neg ? -size : size;

    // Overflow check
    if (size > 3 || (size == 3 && long_object->ob_digit[2] > 15))
    {
        printf("C unsigned long int overflow\n");
        return;
    }

    i = size - 1;
    while (i >= 0)
    {
        // Uses base 2^30 for digits (since PyLong_SHIFT is typically 30)
        result = result * (1 << PyLong_SHIFT) + long_object->ob_digit[i];
        i--;
    }

    if (is_neg)
        printf("-");
    printf("%lu\n", result);
}
