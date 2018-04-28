#include "Pasien.h"

void createList_pasien(List_pasien &L)
{
    // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
    first_pasien(L) = NULL;
}

address_pasien alokasi_pasien(pasien x)
{
    // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
    address_pasien P = new elmList_pasien;
    info_pasien(P) = x;
    next_pasien(P) = NULL;
    return P;
}

void dealokasi_pasien(address_pasien &P)
{
    // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
    delete P;
}

void insertFirst_pasien(List_pasien &L, address_pasien P)
{
    // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
    if(first_pasien(L) == NULL)
    {
        first_pasien(L) = P;
    }
    else
    {
        next_pasien(P) = first_pasien(L);
        first_pasien(L) = P;
    }
}

void insertLast_pasien(List_pasien &L, address_pasien P)
{
    // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
    if (first_pasien(L) == NULL)
    {
        insertFirst_pasien(L,P);
    }
    else
    {
        address_pasien Q = first_pasien(L);
        while (next_pasien(Q)!= NULL)
        {
            Q=next_pasien(Q);
        }
        next_pasien(Q)=P;
    }
}

void insertAfter_pasien(List_pasien &L, address_pasien Prec, address_pasien P)
{
    // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
    if(Prec!=NULL)
    {
        if(next_pasien(Prec)==NULL)
        {
            insertLast_pasien(L, P);
        }
        else
        {
            next_pasien(P)=next_pasien(Prec);
            next_pasien(Prec)=P;
        }
    }
}

address_pasien findElm_pasien(List_pasien L, int pasien)
{
    // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
    address_pasien P;
    P=first_pasien(L);
    while(P != NULL)
    {
        if (pasien==P->info_pasien.idPasien)
        {
            return P;
        }
        P=next_pasien(P);
    }
    return NULL;
}

void deleteFirst_pasien(List_pasien &L, address_pasien &P)
{
    // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
    if (first_pasien(L) == NULL)
    {
        cout<<"data kosong"<<endl;
    }
    else
    {
        if(next_pasien(first_pasien(L))==NULL)
        {
            P = first_pasien(L);
            first_pasien(L) = NULL;
        }
        else
        {
            P=first_pasien(L);
            first_pasien(L)=next_pasien(P);
            next_pasien(P)= NULL;
        }
    }
}

void deleteLast_pasien(List_pasien &L, address_pasien &P)
{
    // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
    if (first_pasien(L) != NULL)
    {
        if (next_pasien(first_pasien(L)) == NULL)
        {
            P = first_pasien(L);
            first_pasien(L) = NULL;
        }
        else
        {
            address_pasien Q = first_pasien(L);
            while (next_pasien(next_pasien(Q)) != NULL)
            {
                Q = next_pasien(Q);
            }
            P = next_pasien(Q);
            next_pasien(Q) = NULL;
        }
    }
}

void deleteAfter_pasien(List_pasien &L,address_pasien Prec, address_pasien &P)
{
    if (Prec!=NULL)
    {
        if(next_pasien(next_pasien(Prec))==NULL)
        {
            deleteLast_pasien(L, P);
        }
        else
        {
            address_pasien Q = next_pasien(P);
            next_pasien(Prec) = Q;
            next_pasien(P) = NULL;
        }
    }
}

void printInfo_pasien(List_pasien L)
{
    // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
    address_pasien P;
    if(first_pasien(L)==NULL)
    {
        cout << "|=======================================================================|" << endl;
        cout << "|\t\t\t  Daftar Pasien Telkom Medika\t\t\t|" << endl;
        cout << "|=======================================================================|" << endl;
        cout<<"|\t\t\t       Tidak Ada Pasien\t\t\t\t|"<<endl;
        cout << "|=======================================================================|" << endl;
    }
    else
    {
        cout << "|=======================================================================|" << endl;
        cout << "|\t\t\t  Daftar Pasien Telkom Medika \t\t\t|"<< endl;
        cout << "|=======================================================================|" << endl;
        cout << "|ID \t| Nama \t| TTL\t| Alamat\t| No Tlp\t| Jenis Penyakit|" << endl;
        cout << "|=======================================================================|" << endl;
        P=first_pasien(L);
        do
        {
            cout<< "|" <<info_pasien(P).idPasien<<"\t| "<<info_pasien(P).nama<<"\t| ";
            cout<<info_pasien(P).ttl<<"\t| "<<info_pasien(P).alamat<<"\t| ";
            cout<<info_pasien(P).noTlp<<"\t\t| "<<info_pasien(P).jpenyakit<<"\t\t| ";
            cout <<endl;
            P=next_pasien(P);
        }
        while(P!=NULL);
        cout<<"\n\n";
    }
}
