#include <Python.h>

/**
 *print_python_string - function to print about list
 *@p: pointer refer to object of python
 *Return:
 */
void print_python_string(PyObject *p)
{

	Py_ssize_t x;
	wchar_t *n;

	printf("[.] string object info\n");
	if (strncmp(p->ob_type->tp_name, "str", 3) != 0)
	{
		printf("  [ERROR] Invalid String Object\n");
		return;
	}
	x = ((PyASCIIObject *)(p))->length;
	n = PyUnicode_AsWideCharString(p, &x);

	if (PyUnicode_IS_COMPACT_ASCII(p) != 0)
		printf("  type: compact ascii\n  length: %lu\n  n: %ls\n",
		x, n);
	else
		printf("  type: compact unicode object\n  length: %lu\n  n: %ls\n",
		x, n);
}
