#include <Python.h>

/**
 *print_python_string - function to print about list
 *@p: pointer refer to object of python
 *Return:
 */
void print_python_string(PyObject *p)
{
	int x = 0;
	char *buffer;

	printf("[.] string object info\n");
	if (PyUnicode_Check(p) && PyUnicode_READY(p) == 0)
	{
		buffer = (char *)PyUnicode_AsUTF8(p);
		x = (int) PyUnicode_GET_LENGTH(p);
		if (PyUnicode_IS_COMPACT_ASCII(p))
		{
			printf("  type: compact ascii\n");
		}
		else
		{
			printf("  type: compact unicode object\n");
		}
		
		printf("  length: %d\n", x);
		printf("  value: %s\n", buffer);
	}
	printf("  [ERROR] Invalid String Object\n");
}
