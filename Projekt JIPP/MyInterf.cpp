#include "pch.h"
#include <iostream>
#include "MyInterf.h"
#include "My_student.h"
#include "My_array.h"
#include <stdlib.h>
#include <string.h>
#include <fstream>

#pragma warning (disable : 4996)
using namespace std;


void My_menu()
{
	//fstream *wsk = NULL;
	int men;
	MY_ARRAY_ELEM *Array = CreateArray(10);

	while (true)
	{
		printf("Witaj! \nPodaj : \n1 - dodaj studenta\n2 - wyswietl liste studentow\n3 - wyczysc plik binarny  \n4- wyjdz z programu\n");
		scanf_s("%d", &men);

		switch (men)
		{
		case 1:
			Dodaj(Array);
			break;
		case 2:
			PrintAllObjects(Array);
			break;
		case 3:
			Czyszczenie(); 
			break;
		case 4:
			MyExit(Array);
			break;
		default:
			printf("unknown operation\n");

		};
	}
}

void MyExit(MY_ARRAY_ELEM * arr)
{
	printf("exit\n");
	//
	//
	FreeArray(&arr);
	system("pause");
	exit(1);
}

void Dodaj(MY_ARRAY_ELEM *arr )
{
	
	MY_STUDENT *st = NULL;
	MY_ARRAY_ELEM tmp;

	st = (MY_STUDENT *)malloc(sizeof(MY_STUDENT));  
	if (!st)
	{
		printf("memory allocation error\n");
		return;
	}

	int k;
	while(true)
	{ 
		printf("To ma byc student matematyki-1 , fizyki-2 czy informatyki-3 , \npodaj liczbe :");
		scanf_s("%d", &k);
		if (k == 1) st->kier = matematyka;
		if (k == 2) st->kier = fizyka;
		if (k == 3) st->kier = informatyka;
		if (k == 1 || k == 2 || k == 3)
		{
			break;
		}
		else printf("Podales zla liczbe!");
	}
	
		StudentInit(st);
		StudentInput(st);

		tmp.ptr_data = (void *)st;
		tmp.ptr_fun_prnt = StudentPrint;
		tmp.ptr_fun_free = StudentFree;

		dodaj_do_pliku(st, k);

		if (!PushObject(arr, &tmp))
		{
			MyInterfDealloc(st);
			printf("Push object error\n");
		}
}

void MyInterfDealloc(void * ptr)
{
	if (ptr)
		free(ptr);
}

void PrintAllObjects(MY_ARRAY_ELEM * arr)
{
	//PrintArray(arr);

	printf("Czytanie z pliku binarnego!\n");

	std::fstream plik;
	plik.open("dane.bin", std::ifstream::binary);
	if (plik.good() == true)
	{
		

		plik.close();
	}

}

void dodaj_do_pliku(MY_STUDENT *stud, int k)
{
	printf("Zapis\n");

	std::fstream plik;
	plik.open("dane.bin", std::ifstream::binary && std::ifstream::ate);
	if (plik.good() == true)
	{
		plik >> stud->nazwisko;
		plik >> k;
		plik >> stud->rocznik;
		plik.close();
	}

	
}

void Czyszczenie()
{
	/*if (wsk != NULL)
	{
		wsk = fopen("dane.bin", "w");
		if (wsk == NULL) exit(-1);
		fclose(wsk);
		wsk = NULL;
	}*/
}