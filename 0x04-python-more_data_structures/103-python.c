#include <stdio.h>
#include <Python.h>

/**
 * print_python_bytes - Prints bytes information
 *
 * @p: Python Object
 * Return: no return
 */

void print_python_bytes(PyObject *p)
{
	PyBytesObject *bytes = (PyBytesObject *)p;
	Py_ssize_t size, i, limit;
	char *string;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = PyBytes_Size(p);
	string = PyBytes_AsString(p);

	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", string);

	limit = (size >= 10) ? 10 : size + 1;

	printf("  first %ld bytes:", limit);
	for (i = 0; i < limit; i++)
	{
		char value = string[i];

		if (value >= 0)
			printf(" %02x", value);
		else
			printf(" %02x", 256 + value);
	}
	printf("\n");
}

/**
 * print_python_list - Prints list information
 *
 * @p: Python Object
 * Return: no return
 */

void print_python_list(PyObject *p)
{
	Py_ssize_t size, i;

	printf("[*] Python list info\n");
	size = PyList_Size(p);
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < size; i++)
	{
		PyObject *item = PyList_GetItem(p, i);
		const char *type_name = item->ob_type->tp_name;

		printf("Element %ld: %s\n", i, type_name);

		if (PyBytes_Check(item))
			print_python_bytes(item);
	}
}
