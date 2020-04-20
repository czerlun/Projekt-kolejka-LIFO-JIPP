#pragma once

struct MY_STUDENT
{
	char *nazwisko;
	int rocznik;
	enum kierunek kier;
};

void StudentInit(MY_STUDENT *ptr);
void StudentPutData(MY_STUDENT *ptr, int rocznik, char *nazw);
void StudentInput(MY_STUDENT *ptr);
void StudentFree(void **pTr);
void StudentPrint(void * pdata);