#include <Python.h>
#include <stdio.h>
#include <stdlib.h>

void print_python_string(PyObject *po)
{
	PyASCIIObject *pao = NULL;

	setbuf(stdout, NULL);
	printf("[.] string object info\n");

	if (!po || po->ob_type != &PyUnicode_Type)
	{
		printf("  [ERROR] Invalid String Object\n");
		return;
	}

	pao = (PyASCIIObject *)po;

	if (pao->state.ascii)
		printf("  type: compact ascii\n");
	else
		printf("  type: compact unicode object\n");

	printf("  length: %lu\n", pao->length);
	printf("  value: %s\n", PyUnicode_AsUTF8(po));
}
