// Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
#ifndef OBAT_H_INCLUDED
#define OBAT_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;

#define info_Obat(P) P->info_Obat
#define next_Obat(P) P->next_Obat
#define prev_Obat(P) P->prev_Obat
#define first_Obat(L) L.first_Obat
#define last_Obat(L) L.last_Obat

typedef struct Obat infotype_obat;

struct Obat
{
    string namaObat;
    string jenisObat;
    string idObat;
    long hargaObat;
};

typedef struct Elmlist_Obat *address_Obat;

struct Elmlist_Obat
{
    infotype_obat info_Obat;
    address_Obat next_Obat;
    address_Obat prev_Obat;
};

struct List_Obat
{
    address_Obat first_Obat;
    address_Obat last_Obat;
};

void createList_Obat(List_Obat &L);
address_Obat alokasi_Obat(Obat x);
void dealokasi_Obat(address_Obat &P);
void insertFirst_Obat(List_Obat &L, address_Obat P);
void insertLast_Obat(List_Obat &L, address_Obat P);
void insertAfter_Obat(List_Obat &L, address_Obat Prec, address_Obat P);
address_Obat findElm_Obat(List_Obat L, string x);
void deleteFirst_Obat(List_Obat &L, address_Obat &P);
void deleteAfter_Obat(List_Obat &L, address_Obat Prec, address_Obat &P);
void deleteLast_Obat(List_Obat &L, address_Obat &P);
void printInfo_Obat(List_Obat L);

#endif // DOKTER_H_INCLUDED
