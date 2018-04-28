#include "Relasi.h"

void createList_relasi(List_relasi &L)
{
    // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
    first_relasi(L) = NULL;
    last_relasi(L) = NULL;
}

address_relasi alokasi_relasi(address_pasien PP, address_Obat PO)
{
    // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
    address_relasi P = new elmList_relasi;
    obt(P) = PO;
    psn(P) = PP;
    next_relasi(P) = NULL;
    return P;
}

void dealokasi_relasi(address_relasi &P)
{
    // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
    delete P;
}

void insertLast_relasi(List_relasi &L, address_relasi P)
{
    // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
    if(first_relasi(L)==NULL)
    {
        first_relasi(L)=P;
        next_relasi(first_relasi(L))=first_relasi(L);
        prev_relasi(first_relasi(L))=first_relasi(L);
    }
    else
    {
        address_relasi Q=prev_relasi(first_relasi(L));
        prev_relasi(P)=Q;
        prev_relasi(first_relasi(L))=P;
        next_relasi(P)=first_relasi(L);
        next_relasi(Q)=P;
        last_relasi(L) = P;
    }
}
address_relasi findElm_relasi(List_relasi L, int x, string y)
{
    // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
    bool cek;
    address_relasi P;
    if(first_relasi(L)!=NULL)
    {
        cek=false;
        P=first_relasi(L);
        while((cek==false)&&(next_relasi(P)!=first_relasi(L)))
        {
            if(info_pasien(psn(P)).idPasien == x)
            {
                if(info_Obat(obt(P)).idObat == y)
                {
                    cek=true;
                    return P;
                }
            }
            else
            {
                P=next_relasi(P);
            }
        }
        if (cek == false)
        {
            if(info_pasien(psn(P)).idPasien == x)
            {
                if(info_Obat(obt(P)).idObat == y)
                {
                    cek=true;
                }
            }
        }
    }
    if(cek!=true)
    {
        return P=NULL;
    }
    return P;
}

void print_relasi(List_relasi L)
{
    // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
    address_relasi P;
    if (first_relasi(L) == NULL)
    {
        cout << "|=======================================================================|" << endl;
        cout << "|\t  Daftar Pasien yang Telah Membeli Obat di Telkom Medika\t|" << endl;
        cout << "|=======================================================================|" << endl;
        cout<<"|\t\t\t     Tidak Ada Pasien\t\t\t\t|"<<endl;
        cout << "|=======================================================================|" << endl;
    }
    else
    {
        cout << "|=======================================================================|" << endl;
        cout << "|\t  Daftar Pasien yang Telah Membeli Obat di Telkom Medika\t|" << endl;
        cout << "|=======================================================================|" << endl;
        cout << "|ID Pasien \t\t|ID Obat \t\t|Alamat Pasien\t\t|" << endl;
        cout << "|=======================================================================|" << endl;
        P = first_relasi(L);
        do
        {
            cout<<"|"<<info_pasien(psn(P)).idPasien<<" \t\t\t| "<<info_Obat(obt(P)).idObat<<"\t\t\t|"<<" "<<info_pasien(psn(P)).alamat<<"\t\t| ";
            cout<<endl;
            P = next_relasi(P);
        }
        while (P != first_relasi(L));
        cout << "|=======================================================================|" << endl;
        cout << endl;
    }
}

void delete_relasi(List_relasi &L, address_relasi &P)
{
    // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
    if(first_relasi(L)!=NULL)
    {
        address_relasi Q = first_relasi(L);
        if(next_relasi(first_relasi(L))==first_relasi(L))
        {
            first_relasi(L) = NULL;
            last_relasi(L) = NULL;
            next_relasi(P) = NULL;
            prev_relasi(P) = NULL;
        }
        else if(P == first_relasi(L)&&next_relasi(P)!=first_relasi(L))
        {
            Q = next_relasi(P);
            first_relasi(L) = Q;
            next_relasi(last_relasi(L)) = Q;
            prev_relasi(Q) = last_relasi(L);
            next_relasi(P) = NULL;
            prev_relasi(P) = NULL;
        }
        else if(P == last_relasi(L))
        {
            Q = prev_relasi(P);
            next_relasi(Q) = first_relasi(L);
            prev_relasi(first_relasi(L)) = Q;
            next_relasi(P) = NULL;
            prev_relasi(P) = NULL;
            last_relasi(L) = Q;
        }
        else
        {
            Q = next_relasi(P);
            address_relasi R = prev_relasi(P);
            next_relasi(R) = Q;
            prev_relasi(Q) = R;
            next_relasi(P) = NULL;
            prev_relasi(P) = NULL;
        }
    }
}

