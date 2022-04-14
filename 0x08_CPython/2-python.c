#include <Python.h>

/**
 * print_python_bytes - prints some basic info about
 * Python lists and Python bytes objects.
 * @p: pointer refer to Python object
 * Return:
 */
void print_python_bytes(PyObject *p)
{
	int x;
	char *string = NULL;
	Py_ssize_t n, size;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = ((PyVarObject *)(p))->ob_size;
	printf("  size: %li\n", size);

	string = ((PyBytesObject *)(p))->ob_sval;
	printf("  trying string: %s\n", string);

	printed_bytes = (size + 1 >= 10) ? 10 : size + 1;
	printf("  first %li bytes:", n);
	for (x = 0; x < n; x++)
		printf(" %02x", (unsigned char)(string[i]));
	putchar('\n');
}
/**
 * print_python_list - prints some basic info about Python lists
 * @p: Python object
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t size = PyList_Size(p);
	Py_ssize_t x;
	PyObject *ptr;

	if (!p)
		return;
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", size);
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
	for (x = 0; x < size; x++)
	{
		ptr = ((PyListObject *)(p))->ob_ptr[x];
		printf("Element %ld: %s\n", x, ptr->ob_type->tp_name);
		if (PyBytes_Check(ptr))
			print_python_bytes(ptr);
	}
}
