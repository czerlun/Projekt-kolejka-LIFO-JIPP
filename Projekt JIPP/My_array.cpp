#include "pch.h"
#include "My_array.h"
#include <stdlib.h>

size_t MY_ARRAY_ELEM::last = 0;   //Initiation of static member of structure

MY_ARRAY_ELEM * CreateArray(size_t dim)
{
	MY_ARRAY_ELEM * my_array = (MY_ARRAY_ELEM *)malloc(dim * sizeof(MY_ARRAY_ELEM));
	if (my_array)
		memset((void *)my_array, 0, dim * sizeof(MY_ARRAY_ELEM));
	return my_array;
}

void FreeArray(MY_ARRAY_ELEM ** arr)
{
	if (arr)
	{
		if (*arr)
		{
			size_t it, no_items = (*arr)[0].last;
			for (it = 0; it < no_items; ++it)
			{
				//OK - wywolujemy przez wskaznik funkcje z obslugi danych,
				//ktora zwalnia pamiec dla obiektu (*arr)[it].ptr_data, alokowana
				//dynamicznie.
				(*(*arr)[it].ptr_fun_free)(&(*arr)[it].ptr_data);

				//!OK, poniewaz ptr_data zawiera wskazniki, które wskazuja do heap - gubimy pamiec!!
				/*
				if ((*arr)[it].ptr_data)
					free((*arr)[it].ptr_data);
				(*arr)[it].ptr_data = NULL; */
			}

			free(*arr);
			*arr = NULL;
		}
	}
}

int PushObject(MY_ARRAY_ELEM * arr, MY_ARRAY_ELEM *obj)
{
	size_t last, no_items = _msize(arr) / sizeof(arr[0]);
	last = arr[0].last;

	if (last >= no_items)
	{
		arr = (MY_ARRAY_ELEM *)realloc(arr, 2 * no_items * sizeof(MY_ARRAY_ELEM));
		if (!arr)
			return 0;

		memset((void *)(arr + no_items), 0, no_items * sizeof(MY_ARRAY_ELEM));
	}

	arr[last].ptr_data = obj->ptr_data;
	arr[last].ptr_fun_prnt = obj->ptr_fun_prnt;
	arr[last].ptr_fun_free = obj->ptr_fun_free;
	arr[0].last = ++last;

	return 1;
}


void PrintArray(MY_ARRAY_ELEM * arr)
{
	size_t it, no_items = arr[0].last;

	for (it = 0; it < no_items; ++it)
	{
		(*arr[it].ptr_fun_prnt)(arr[it].ptr_data);
	}
}
