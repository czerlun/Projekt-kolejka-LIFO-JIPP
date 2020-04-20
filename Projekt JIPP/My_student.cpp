#include "pch.h"
#include <iostream>
#include "MyInterf.h"
#include "My_student.h"
#include "My_array.h"
#include <stdlib.h>
#include <string.h>
#include <fstream>

void StudentInit(MY_STUDENT *ptr)
{
	if (ptr)
	{
		ptr->rocznik = NULL;
		ptr->nazwisko = NULL;
	}
}


void StudentPutData(MY_STUDENT *ptr, int rocznik, char *nazw)
{
	ptr->nazwisko = (char*)calloc(strlen(nazw) , sizeof(char));

	if (!ptr->nazwisko)
	{
		printf("memory allocation error\n");
		exit(-1);
	}

	strcpy_s(ptr->nazwisko, strlen(nazw)+1, nazw);

	ptr->rocznik = rocznik;

}

void StudentInput(MY_STUDENT *ptr)
{
	printf("Podaj nazwisko studenta: \n");
	char str[64];
	int x;

	scanf_s("%s", str, sizeof(str));
	printf("Podaj rocznik studenta: ");
	scanf_s("%d", &x);
	
	StudentPutData(ptr, x, str);
}

void StudentPrint(void * pdata)
{
	MY_STUDENT *ptr = (MY_STUDENT *)pdata;

	printf("Student %s  kierunek = %d Rocznik = %d\n", ptr->nazwisko, ptr->kier, ptr->rocznik);

}

void StudentFree(void **pTr)
{
		
		free(*pTr);
		*pTr = NULL;
}

