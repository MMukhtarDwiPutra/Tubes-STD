// Dibuat oleh Mia Sayida Fatma - 1301164555 dan Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "Pasien.h"
#include "Obat.h"
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iostream>
using namespace std;

#define info_relasi(P) (P)->info_relasi
#define next_relasi(P) (P)->next_relasi
#define prev_relasi(P) (P)->prev_relasi
#define first_relasi(L) (L).first_relasi
#define last_relasi(L) (L).last_relasi

typedef struct elmList_relasi *address_relasi;

struct elmList_relasi
{
    address_relasi next_relasi;
    address_relasi prev_relasi;
    address_Obat obt;
    address_pasien psn;
};

struct List_relasi
{
    address_relasi first_relasi;
    address_relasi last_relasi;
};

void createList_relasi(List_relasi &L);
address_relasi alokasi_relasi(address_pasien PP, address_Obat PO);
void dealokasi_relasi(address_relasi &P);
void insertLast_relasi(List_relasi &L, address_relasi P);
address_relasi findElm_relasi(List_relasi L, int x, string y);
void print_relasi(List_relasi L);
void delete_relasi(List_relasi &L, address_relasi &P);


#endif // RELASI_H_INCLUDED
