#include <Python.h>

/**
* print_python_int - Print information about a Python Int object.
*
* This function prints information about a Python Int object
*
* @p: A pointer to the Python Int object.
*/
void print_python_int(PyObject *p)
{
	Py_ssize_t size, i;
	unsigned long result = 0;
	PyLongObject *long;

	if (PyLong_Check(p) == 0)
	{
		printf("Invalid Int Object\n");
		return;
	}
	long = (PyLongObject *)p;
	size = long->ob_base.ob_size;
	if (size < 0)
	{
		printf("-");
		size = -size;
	}
	if (size > 3 || (size == 3 && long->ob_digit[2] > 15))
	{
		printf("C unsigned long int overflow\n");
		return;
	}
	i = size - 1
	while (i >= 0)
	{
		result = result * (1 << PyLong_SHIFT) + long->ob_digit[i];
		i--;
	}
	printf("%lu\n", result);
}
