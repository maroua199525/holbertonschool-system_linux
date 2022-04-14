#include <Python.h>

/**
 *print_python_string - function to print about list
 *@p: pointer refer to object of python
 *Return:
 */
void print_python_string(PyObject *p)
{
	wchar_t *buffer = NULL;

	printf("[.] string object info\n");

	if (!PyUnicode_Check(p) || !((PyASCIIObject *)p)->state.ready)
	{
		printf("  [ERROR] Invalid String Object\n");
		return;
	}

	printf("  type: %s%s\n",
	       ((PyASCIIObject *)p)->state.compact ? "compact " : "",
	       ((PyASCIIObject *)p)->state.ascii ? "ascii" : "unicode object");

	printf("  length: %li\n",
	       ((PyASCIIObject *)(p))->length);
	buffer = PyUnicode_AsWideCharString(p, NULL);
	if (buffer != NULL)
	{
		printf("  value: %ls\n", buffer);

		PyMem_Free(buffer);
	}
}
