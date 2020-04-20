#pragma once

#include "My_array.h"
#include "My_student.h"

using namespace std;

void My_menu();
void MyExit(MY_ARRAY_ELEM * arr);
void Dodaj(MY_ARRAY_ELEM *Array);
void MyInterfDealloc(void * ptr);
void PrintAllObjects(MY_ARRAY_ELEM * arr);
void dodaj_do_pliku( MY_STUDENT *st, int k);
void Czyszczenie();