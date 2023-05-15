#include <Python.h>

/**
 * print_python_list_info - Print basic info about Python lists.
 * @p: A Python object.
 *
 */
void print_python_list_info(PyObject *p)
{
	long int size = PyList_Size(p);
	int allocate, i;
	PyObject *obj;

	allocate = ((PyListObject *)p)->allocated;
	
	printf("[*] Size of the Python List = %i\n", size);
	printf("[*] Allocated = %i\n", alloc);
	for (i = 0; i < size; i++)
	{
		printf("Element %i: ", i);

		obj = PyList_GetItem(p, i);
		printf("%s\n", Py_TYPE(obj)->tp_name);
	}
}
