#include <Python.h>


/**
 *print_python_int - function to print integer information
 *@p: pointer to  a list of python
 *Return: Nothing
 */
void print_python_int(PyObject *p)
{
	unsigned long x = 0;
		digit *arr;
	Py_ssize_t size, i, n;


	if (PyLong_Check(p))
	{
		arr = ((PyLongObject *)(p))->ob_digit;
		size = ((PyVarObject *)(p))->ob_size;
		n = abs(size);
		if (n > 3 || (n == 3 && arr[2] > 15))
		{
			printf("C unsigned long int overflow\n");
			return;
		}
		for (i = 0; i < n; i++)
		x += arr[i] * (1L << (30 * i));
		if (size < 0)
		printf("-");
		printf("%lu\n", x);
	}
	else
	{
		printf("Invalid Int Object\n");
		return;
	}
}
