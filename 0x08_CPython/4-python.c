#include <Python.h>
#include <stdio.h>
#include <stdlib.h>

void print_python_string(PyObject *po)
{
    setbuf(stdout, NULL);
    printf("[.] string object info\n");

    // Validate input object
    if (!po || !PyUnicode_Check(po))
    {
        printf("  [ERROR] Invalid String Object\n");
        return;
    }

    // Get string length
    Py_ssize_t length = PyUnicode_GET_LENGTH(po);
    printf("  length: %zd\n", length);

    // Determine string type and value
    if (PyUnicode_IS_COMPACT_ASCII(po))
    {
        printf("  type: compact ascii\n");
        printf("  value: %s\n", PyUnicode_1BYTE_DATA(po));
    }
    else
    {
        printf("  type: compact unicode object\n");

        // Print the Unicode string as UTF-8
        const char *utf8_value = PyUnicode_AsUTF8(po);
        if (utf8_value)
        {
            printf("  value: %s\n", utf8_value);
        }
        else
        {
            printf("  [ERROR] Unable to convert to UTF-8\n");
        }
    }
}