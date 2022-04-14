#include <Python.h>
/**
 * print_python_float - prints some basic info about Python lists
 * @p:pointer refer to object of python
 * Return
 */
void print_python_float(PyObject *p)
{
	double n;
	char *str;

	setbuf(stdout, NULL);

	printf("[.] float object info\n");
	if (!p || !PyFloat_Check(p))
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}

	n = (((PyFloatObject *)(p))->ob_fval);
	str = PyOS_double_to_string(n, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
	printf("  n: %s\n", str);
}
/**
 * print_python_bytes - prints some basic info about Python lists
 * @p: Python object
 */
void print_python_bytes(PyObject *p)
{
	char *str;
	Py_ssize_t size;
	Py_ssize_t i;

	setbuf(stdout, NULL);
	printf("[.] bytes object info\n");
	if (!p || !PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	size = (((PyVarObject *)(p))->ob_size);
	str = (((PyBytesObject *)(p))->ob_sval);

	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", str);
	size = size > 9 ? 10 : size + 1;
	printf("  first %ld bytes: ", size);

	for (i = 0; i < size; i++)
		printf("%02hhx%c", str[i], i < size - 1 ? ' ' : '\n');
}

/**
 * print_python_list - prints some basic info about Python lists
 * @p: Python object
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t size, i;
	PyObject *tmp;

	setbuf(stdout, NULL);
	if (!p || !PyList_Check(p))
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}

	size = (((PyVarObject *)(p))->ob_size);
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", size);
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < size; i++)
	{
		tmp = ((PyListObject *)(p))->ob_item[i];
		printf("Element %ld: %s\n", i, tmp->ob_type->tp_name);
		if (PyBytes_Check(tmp))
			print_python_bytes(tmp);
		else if (PyFloat_Check(tmp))
			print_python_float(tmp);
	}
}
