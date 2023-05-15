#include <Python.h>

/**
 * print_python_list_info - Print basic info about Python lists.
 * @p: A Python object.
 *
 */
void print_python_list_info(PyObject *p)
{
	Py_ssize_t size = PyList_Size(p);
    	Py_ssize_t alloc = ((PyListObject *)p)->allocated;

    	printf("[*] Size of the Python List = %zd\n", size);
   	 printf("[*] Allocated = %zi\n", alloc);

    	for (Py_ssize_t i = 0; i < size; i++)
   	 {
        	PyObject *obj = PyList_GetItem(p, i);
        	typeName = Py_TYPE(obj)->tp_name;
        	printf("Element %zi: %s\n", i, typeName);
    	 }
}
