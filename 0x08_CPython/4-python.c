#include <Python.h>
#include <stdio.h>
#include <stdlib.h>

void print_python_string(PyObject *p)
{
	/* PyASCIIObject *pao = NULL;*/ 

	setbuf(stdout, NULL);
	printf("[.] string object info\n");

	if (!p || p->ob_type != &PyUnicode_Type)
	{
		printf("  [ERROR] Invalid String Object\n");
		return;
	}
if (PyUnicode_IS_COMPACT_ASCII(p))
{
    printf("  type: compact ascii\n");
}
else
{
    printf("  type: compact unicode object\n");
}
    /* Retrieve the length of the string */ 
printf("  length: %zi\n", PyUnicode_GetLength(p));

    /* Determine the type and value*/
printf("  value: %s\n", PyUnicode_AsUTF8(p));
    
}