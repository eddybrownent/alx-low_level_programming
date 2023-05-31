#include <Python.h>

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);
void print_python_float(PyObject *p);

/**
 * print_python_list - Prints basic info about Python lists.
 * @p: A PyObject list object.
 */

void print_python_list(PyObject *p)
{
	Py_ssize_t size = PyList_Size(p);
	Py_ssize_t allocated = ((PyListObject *)p)->allocated;

	if (!PyList_Check(p))
	{
		printf("[ERROR] Invalid PyListObject\n");
		return;
	}

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", allocated);

	for (Py_ssize_t i = 0; i < size; i++)
	{
		PyObject *item = PyList_GetItem(p, i);
		const char *typeName = item->ob_type->tp_name;

		printf("Element %ld: %s\n", i, typeName);
		if (strcmp(typeName, "bytes") == 0)
		{
			print_python_bytes(item);
		}
		else if (strcmp(typeName, "float") == 0)
		{
			print_python_float(item);
		}
	}
}

/**
* print_python_bytes - Prints basic info about Python byte objects.
* @p: A PyObject byte object.
*/

void print_python_bytes(PyObject *p)
{
	Py_ssize_t size = PyBytes_Size(p);
	const char *data = PyBytes_AsString(p);

	if (!PyBytes_Check(p))
	{
		printf("[ERROR] Invalid PyBytesObject\n");
		return;
	}


	printf("[.] bytes object info\n");
	printf("  - Length: %ld\n", size);
	printf("  - Address of the first byte: %p\n", (void *)data);

	printf("  - Bytes: ");
	for (Py_ssize_t i = 0; i < size && i < 10; i++)
	{
		printf("%02hhx", data[i]);
		if (i < size - 1 && i < 9)
		{
			printf(" ");
		}
	}
	printf("\n");
}

/**
 * print_python_float - Prints basic info about Python float objects.
 * @p: A PyObject float object.
 */

void print_python_float(PyObject *p)
{
	double value = PyFloat_AsDouble(p);

	if (!PyFloat_Check(p))
	{
		printf("[ERROR] Invalid PyFloatObject\n");
		return;
	}

	printf("[.] float object info\n");
	printf("  - Value: %.17g\n", value);
}
