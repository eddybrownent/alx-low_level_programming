#include <python.h>
#include <listobject.h>
#include <object.h>

/**
 * print_python_list_info  -  print basic info about python lists
 * @p: python object
 *
 */
void print_python_list_info(PyObject *p)
{
	PyObject *obj = (PyListObject *)p;
	int i;
	int size = PyList_Size(p);

	printf("[*] Size of the python List = %d\n", size);
	printf("[*] Allocated = %d\n", obj->allocated);
	for (i = 0; i < size; i++)
	{
		printf("Element %d: %s\n", i, Py_TYPE(obj->ob_item[i]->tp_name);
	}
}
