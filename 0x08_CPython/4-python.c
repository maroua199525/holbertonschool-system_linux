#include <Python.h>
#include <stdio.h>

void print_python_string(PyObject *po)
{
    if (!PyUnicode_Check(po))
    {
        fprintf(stderr, "Invalid Unicode object\n");
        return;
    }

    printf("[.] string object info\n");

    /* Get Unicode kind */
    Py_ssize_t length = PyUnicode_GET_LENGTH(po);
    const char *utf8_str = PyUnicode_AsUTF8(po);

    /* Print the type */
    if (PyUnicode_IS_COMPACT_ASCII(po))
        printf("  type: compact ascii\n");
    else
        printf("  type: compact unicode object\n");

    /* Print the length */
    printf("  length: %zd\n", length);

    /* Print the UTF-8 value */
    printf("  value: %s\n", utf8_str);
}
