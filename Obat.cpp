#include "Obat.h"

void createList_Obat(List_Obat &L)
{
    // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
    first_Obat(L) = NULL;
    last_Obat(L) = NULL;
}

address_Obat alokasi_Obat(Obat x)
{
    // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
    address_Obat P = new Elmlist_Obat;
    info_Obat(P)= x;
    next_Obat(P) = NULL;
    prev_Obat(P) = NULL;
    return P;
}

void dealokasi_Obat(address_Obat &P)
{
    // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
    delete P;
}

void insertFirst_Obat(List_Obat &L, address_Obat P)
{
    // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
    address_Obat Q;
    if(first_Obat(L)==NULL)
    {
        first_Obat(L)=P;
        next_Obat(P)=first_Obat(L);
        last_Obat(L) = P;
        prev_Obat(P) = P;
    }
    else
    {
        Q=last_Obat(L);
        next_Obat(P)=first_Obat(L);
        prev_Obat(first_Obat(L)) = P;
        first_Obat(L)=P;
        next_Obat(Q)=P;
        prev_Obat(P)=Q;
    }
}

void insertLast_Obat(List_Obat &L, address_Obat P)
{
    // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
    address_Obat Q;
    if(first_Obat(L)==NULL)
    {
        insertFirst_Obat(L, P);
    }
    else
    {
        Q = last_Obat(L);
        next_Obat(Q)=P;
        next_Obat(P)=first_Obat(L);
        prev_Obat(P)=Q;
        prev_Obat(first_Obat(L))=P;
        last_Obat(L) = P;
    }
}

void insertAfter_Obat(List_Obat &L, address_Obat Prec, address_Obat P)
{
    // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
    if(Prec!=NULL)
    {
        if(next_Obat(Prec)==first_Obat(L))
        {
            insertLast_Obat(L, P);
        }
        else
        {
            address_Obat O = next_Obat(Prec);
            next_Obat(Prec) = P;
            prev_Obat(P) = Prec;
            next_Obat(P) = O;
            prev_Obat(O) = P;
        }
    }
}

void deleteFirst_Obat(List_Obat &L, address_Obat &P)
{
    // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
    if(first_Obat(L)!=NULL)
    {
        if(next_Obat(first_Obat(L))==first_Obat(L))
        {
            P = first_Obat(L);
            first_Obat(L) = NULL;
            last_Obat(L) = NULL;
        }
        else
        {
            address_Obat Q = last_Obat(L);
            P=first_Obat(L);
            first_Obat(L)=next_Obat(first_Obat(L));
            next_Obat(P)=NULL;
            prev_Obat(first_Obat(L))=Q;
            next_Obat(Q)=first_Obat(L);
            prev_Obat(P) = NULL;
        }
    }
}

void deleteAfter_Obat(List_Obat &L, address_Obat Prec, address_Obat &P)
{
    // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
    if(Prec!=NULL)
    {
        if(first_Obat(L)!=NULL)
        {
            if(next_Obat(Prec) == first_Obat(L))
            {
                deleteFirst_Obat(L, P);
            }
            else if (next_Obat(Prec)==last_Obat(L))
            {
                deleteLast_Obat(L, P);
            }
            else
            {
                next_Obat(Prec) = next_Obat(P);
                prev_Obat(next_Obat(P)) = Prec;
                next_Obat(P) = NULL;
                prev_Obat(P) = NULL;
            }
        }
    }
}

void deleteLast_Obat(List_Obat &L, address_Obat &P)
{
    // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
    if(first_Obat(L)!=NULL)
    {
        if(next_Obat(first_Obat(L))==first_Obat(L))
        {
            deleteFirst_Obat(L, P);
        }
        else
        {
            P = last_Obat(L);
            last_Obat(L) = prev_Obat(last_Obat(L));
            next_Obat(last_Obat(L)) = first_Obat(L);
            prev_Obat(first_Obat(L)) = last_Obat(L);
            next_Obat(P) = NULL;
            prev_Obat(P) = NULL;
        }
    }
}

void printInfo_Obat(List_Obat L)
{
    // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
    address_Obat P;
    if(first_Obat(L)==NULL)
    {
        cout << "|===============================================================|" << endl;
        cout << "|\t\t  Daftar Pasien Telkom Medika\t\t\t|" << endl;
        cout << "|===============================================================|" << endl;
        cout<<"|\t\t      Tidak Ada Pasien \t\t\t\t|" << endl;
        cout << "|===============================================================|" << endl;
    }
    else
    {
        system("cls");
        cout << "|===============================================================|" << endl;
        cout << "|\t\t  Daftar Pasien Telkom Medika\t\t\t|" << endl;
        cout << "|===============================================================|" << endl;
        cout << "|Nama Obat\t| Jenis Obat\t|  Id Obat\t|  Harga\t|" << endl;
        cout << "|===============================================================|" << endl;
        P=first_Obat(L);
        while(next_Obat(P)!=first_Obat(L))
        {
            cout<<"|"<<info_Obat(P).namaObat<<"\t\t| "<<info_Obat(P).jenisObat<<"\t\t|["<<info_Obat(P).idObat<<"]\t\t|" <<info_Obat(P).hargaObat <<"\t\t|" ;
            cout<<endl;
            P=next_Obat(P);

        }
        cout<<"|"<<info_Obat(P).namaObat<<"\t\t| "<<info_Obat(P).jenisObat<<"\t\t|["<<info_Obat(P).idObat<<"]\t\t|" <<info_Obat(P).hargaObat <<"\t\t|" <<endl;
        cout << "|===============================================================|" << endl;
        cout<<"\n\n";
    }
}

address_Obat findElm_Obat(List_Obat L, string Obat)
{
    // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
    address_Obat P;
    P=first_Obat(L);
    if(P!=NULL)
    {
        do
        {
            if (Obat==P->info_Obat.idObat)
            {
                return P;
            }
            P=next_Obat(P);
        }
        while(P != first_Obat(L));
    }
    return NULL;
}
