#pragma once

typedef void(*PrintObject)(void * pdat);
typedef void(*FreeObject)(void ** pdat);

struct MY_ARRAY_ELEM
{
	void *ptr_data;				//pointer to data
	PrintObject ptr_fun_prnt;   //wskaznik do funkcji, ktora drukuje obiekt danych
	FreeObject  ptr_fun_free;   //wskaznik do funkcji z obslugi danych, ktora zwalnia pamiec
	static size_t last;			//last position, which is free
};

MY_ARRAY_ELEM * CreateArray(size_t dim);
void FreeArray(MY_ARRAY_ELEM ** arr);

int PushObject(MY_ARRAY_ELEM * arr, MY_ARRAY_ELEM *obj);
void PrintArray(MY_ARRAY_ELEM * arr);