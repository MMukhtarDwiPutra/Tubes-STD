 // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
#ifndef PASIEN_H_INCLUDED
#define PASIEN_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;

#define info_pasien(P) (P)->info_pasien
#define next_pasien(P) (P)->next_pasien
#define first_pasien(L) (L).first_pasien
#define obt(P) (P)->obt
#define psn(P) (P)->psn

struct pasien
{
    string nama;
    string ttl;
    int idPasien;
    string alamat;
    string jpenyakit;
    string noTlp;
};

typedef struct elmList_pasien* address_pasien;

struct elmList_pasien
{
    pasien info_pasien;
    address_pasien next_pasien;
};

struct List_pasien
{
    address_pasien first_pasien;
};

void createList_pasien(List_pasien &L);
address_pasien alokasi_pasien(pasien x);
void dealokasi_pasien(address_pasien &P);
void insertFirst_pasien(List_pasien &L, address_pasien P);
void insertLast_pasien(List_pasien &L, address_pasien P);
void insertAfter_pasien(address_pasien Prec, address_pasien P);
address_pasien findElm_pasien(List_pasien L, int x);
void deleteFirst_pasien(List_pasien &L, address_pasien &P);
void deleteLast_pasien(List_pasien &L, address_pasien &P);
void deleteAfter_pasien(List_pasien &L,address_pasien Prec, address_pasien &P);
void printInfo_pasien(List_pasien L);

#endif // PASIEN_H_INCLUDED
