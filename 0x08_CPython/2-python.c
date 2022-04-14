#include <Python.h>

/**
 * print_python_bytes - prints some basic info about
 * Python lists and Python bytes objects.
 * @p: pointer refer to Python object
 * Return:
 */
void print_python_bytes(PyObject *p)
{
	int i;
	Py_ssize_t obj_bytes;
	char *str = NULL;
	Py_ssize_t size;

	printf("[.] bytes object info\n");
	if (PyBytes_Check(p))
	{
		size = ((PyVarObject *)(p))->ob_size;
		printf("  size: %li\n", size);

		str = ((PyBytesObject *)(p))->ob_sval;
		printf("  trying string: %s\n", str);

		obj_bytes = (size + 1 >= 10) ? 10 : size + 1;
		printf("  first %li bytes:", obj_bytes);
		for (i = 0; i < obj_bytes; i++)
			printf(" %02x", (unsigned char)(str[i]));
		putchar('\n');
	}
	else
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
}
/**
 * print_python_list - prints some basic info about Python lists
 * @p: Python object
 */
void print_python_list(PyObject *p)
{
	PyObject *ptr;
	Py_ssize_t size = PyList_Size(p), x;

	if (!p)
		return;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", size);
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);

	for (x = 0; x < size; x++)
	{
		ptr = ((PyListObject *)(p))->ob_item[x];
		printf("Element %ld: %s\n", x, ptr->ob_type->tp_name);
		if (PyBytes_Check(ptr))
			print_python_bytes(ptr);
	}
}
