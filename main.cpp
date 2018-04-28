#include <iostream>
#include "Pasien.h"
#include "Obat.h"
#include "Relasi.h"
#include "case_functional.h"


using namespace std;

int main()
{
    address_pasien PP,pq;
    address_Obat PO;
    address_relasi q,r;
    infotype_obat obat;
    bool terdaftar,habis;
    List_Obat LO;
    List_relasi LR;
    createList_relasi(LR);
    createList_Obat(LO);
    List_pasien LP;
    createList_pasien(LP);
    pasien p;
    int menu, pi;
    string oi;
    do
    {
        terdaftar = false;
        system("CLS");
        cout << "===========MENU============" << endl;
        cout << "1. Insert parent" << endl;
        cout << "2. Print all parent" << endl;
        cout << "3. Insert child" << endl;
        cout << "4. Print child" << endl;
        cout << "5. Connect "<< endl;
        cout << "6. Check connection" << endl;
        cout << "7. Disconnect" << endl;
        cout << "8. Print all" << endl;
        cout << "9. Print child of a Parent" << endl;
        cout << "10. Delete child" << endl;
        cout << "11. Delete parent" << endl;
        cout << "12. Jumlah rata rata harga pada suatu jenis obat yang sudah dibeli" << endl;
        cout << "13. Jumlah harga obat yang telah dikeluarkan oleh pasien" << endl;
        cout << "Masukkan nomor menu : ";
        cin >> menu;
        switch(menu)
        {
        case 1 :
        {
             // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
            system("CLS");
            cout << "Masukkan ID : ";
            cin >> p.idPasien;
            cout << "Masukkan nama pasien : ";
            cin >> p.nama;
            cout << "Tempat tanggal lahir : ";
            cin >> p.ttl;
            cout << "Alamat : ";
            cin >> p.alamat;
            cout << "Jenis penyakit : ";
            cin >> p.jpenyakit;
            cout << "Nomor telepon : ";
            cin >> p.noTlp;
            address_pasien P = alokasi_pasien(p);
            if(first_pasien(LP)==NULL)
            {
                insertFirst_pasien(LP, P);
            }
            else
            {
                address_pasien Q = first_pasien(LP);
                while(Q!=NULL)
                {
                    if(info_pasien(Q).idPasien == p.idPasien)
                    {
                        terdaftar = true;
                    }
                    Q = next_pasien(Q);
                }
                if(!terdaftar)
                {
                    insertLast_pasien(LP, P);
                }
                else
                {
                    cout << "ID telah ada!" << endl;
                }
            }
            getch();
        }
        break;
        case 2 :
        {
            system("CLS");
            printInfo_pasien(LP);
            getch();
        }
        break;
        case 3 :
        {
            // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
            system("CLS");
            cout << "Masukkan ID obat : ";
            cin >> obat.idObat;
            cout << "Masukkan nama obat : ";
            cin >> obat.namaObat;
            cout << "Masukkan jenis obat : ";
            cin >> obat.jenisObat;
            cout << "Masukkan harga obat : ";
            cin >> obat.hargaObat;
            address_Obat C = alokasi_Obat(obat);
            if(first_Obat(LO)==NULL)
            {
                insertFirst_Obat(LO, C);
            }
            else
            {
                address_Obat W = first_Obat(LO);
                do
                {
                    if(info_Obat(W).idObat == info_Obat(C).idObat)
                    {
                        terdaftar = true;
                    }
                    W = next_Obat(W);
                }
                while(W!=first_Obat(LO));
                if(!terdaftar)
                {
                    insertLast_Obat(LO, C);
                }
                else
                {
                    cout << "ID obat telah terdaftar!" << endl;
                }
            }
            getch();
        }
        break;
        case 4 :
        {
            system("CLS");
            printInfo_Obat(LO);
            getch();
        }
        break;
        case 5 :
        {
            // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
            system("CLS");
            cout << "Insert relasi" << endl;
            cout << "Masukkan id pasien : ";
            cin >> pi;
            cout << "Masukkan id obat : ";
            cin >> oi;
            PP = findElm_pasien(LP, pi);
            PO = findElm_Obat(LO, oi);
            if(PP!=NULL && PO !=NULL)
            {
                r = alokasi_relasi(PP, PO);
                insertLast_relasi(LR, r);
                cout << "Relasi telah disambungkan!" << endl;
            }
            else
            {
                cout << "id parent atau id child tidak ditemukan!" << endl;
            }
            getch();
        }
        break;
        case 6 :
        {
            // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
            system("CLS");
            cout << "Check connection" << endl;
            cout << "Masukkan id pasien : ";
            cin >> pi;
            cout << "Masukkan id obat : ";
            cin >> oi;
            PP = findElm_pasien(LP, pi);
            PO = findElm_Obat(LO, oi);
            if(PP!=NULL && PO!=NULL)
            {
                if(first_relasi(LR)!=NULL)
                {
                    r = findElm_relasi(LR, pi, oi);
                    if(r!=NULL)
                    {
                        cout << "Parent dengan id : " << info_pasien(PP).idPasien << " terhubung dengan child yang ber-id : " << info_Obat(PO).idObat << endl;
                    }
                    else
                    {
                        cout << "Parent dengan id : " << info_pasien(PP).idPasien << " tidak terhubung dengan child yang ber-id : " << info_Obat(PO).idObat << endl;
                    }
                }
                else
                {
                    cout << "Relasi belum ada!" << endl;
                }
            }
            else
            {
                cout << "Salah satu id parent atau id child tidak ditemukan!" << endl;
            }
            getch();
        }
        break;
        case 7 :
        {
            // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
            system("CLS");
            cout << "Disconnect" << endl;
            cout << "Masukkan id pasien : ";
            cin >> pi;
            cout << "Masukkan id obat : ";
            cin >> oi;
            PP = findElm_pasien(LP, pi);
            PO = findElm_Obat(LO, oi);
            if(PP==NULL)
            {
                cout << "ID parent " << pi << " tidak ditemukan."<<endl;
            }
            if(PO==NULL)
            {
                cout << "ID child " << oi << " tidak ditemukan."<<endl;
            }
            if(PP!=NULL && PO!=NULL)
            {
                r = findElm_relasi(LR, pi, oi);
                if(r!=NULL)
                {
                    delete_relasi(LR, r);
                    dealokasi_relasi(r);
                    cout << "Relasi telah diputus" << endl;
                }
            }
            getch();
        }
        break;
        case 8 :
        {
            system("CLS");
            print_relasi(LR);
            getch();
        }
        break;
        case 9 :
        {
            // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
            system("CLS");
            cout << "Print child of a Parent" << endl;
            cout << "Masukkan id pasien : ";
            cin >> pi;
            PP = findElm_pasien(LP, pi);
            r = first_relasi(LR);
            if(PP==NULL)
            {
                cout << "ID parent " << pi << " tidak ditemukan."<<endl;
            }
            else
            {
                cout << "ID pasien (parentList id) : " << info_pasien(PP).idPasien << endl;
                if(r!=NULL)
                {
                    cout << "   ID obat (childList id) : ";
                    do
                    {
                        if(psn(r)==PP)
                        {
                            cout << " - >" <<info_Obat(obt(r)).idObat;
                        }
                        r = next_relasi(r);
                    }
                    while(r!=first_relasi(LR));
                }
            }
            if(first_relasi(LR)==NULL)
            {
                cout << "Tidak ada relasi apapun" << endl;
            }
            getch();
        }
        break;
        case 10 :
        {
            // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
            system("CLS");
            cout << "Delete child" << endl;
            cout << "Masukkan id obat : ";
            cin >> oi;
            PO = findElm_Obat(LO, oi);
            r = first_relasi(LR);
            if(PO==NULL)
            {
                cout << "ID child " << oi << " tidak ditemukan." << endl;
            }
            else
            {
                if(r!=NULL)
                {
                    habis = false;
                    bool tanda = false;
                    address_relasi awal = NULL;
                    do
                    {
                        if(obt(r)==PO)
                        {
                            q = next_relasi(r);
                            delete_relasi(LR,r);
                            dealokasi_relasi(r);
                            r = q;
                        }
                        else
                        {
                            if(!tanda)
                            {
                                awal = r;
                                tanda = true;
                            }
                            r = next_relasi(r);
                        }
                        if(awal == r)
                        {
                            habis = true;
                        }
                    }
                    while(!habis);
                }

                address_Obat Prec = prev_Obat(PO);
                deleteAfter_Obat(LO, Prec, PO);
                dealokasi_Obat(PO);
                cout << "Child sudah di hapus!" << endl;
            }
            getch();
        }
        break;
        case 11 :
        {
            // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
            system("CLS");
            cout << "Delete parent" << endl;
            cout << "Masukkan id pasien : ";
            cin >> pi;
            PP = findElm_pasien(LP, pi);
            if(PP==NULL)
            {
                cout << "ID parent " << pi << " tidak ditemukan." << endl;
            }
            else
            {
                r = first_relasi(LR);
                if(r!=NULL)
                {
                    habis = false;
                    bool tanda = false;
                    address_relasi awal = NULL;
                    do
                    {
                        if(psn(r)==PP)
                        {
                            q = next_relasi(r);
                            delete_relasi(LR,r);
                            dealokasi_relasi(r);
                            r = q;
                        }
                        else
                        {
                            if(!tanda)
                            {
                                awal = r;
                                tanda = true;
                            }
                            r = next_relasi(r);
                        }
                        if(awal == r)
                        {
                            habis = true;
                        }
                    }
                    while(!habis);
                }

                pq = first_pasien(LP);
                if(pq == PP)
                {
                    deleteFirst_pasien(LP,PP);
                }
                else
                {
                    while(next_pasien(pq)!=PP)
                    {
                        pq = next_pasien(pq);
                    }
                    deleteAfter_pasien(LP, pq, PP);
                }
                dealokasi_pasien(PP);
                cout << "Parent sudah dihapus!" << endl;
            }
            getch();
        }
        break;
        case 12 :
        {
            system("CLS");
            rataHargaObat(LR, LO);
            getch();
        }
        break;
        case 13 :
        {
            system("CLS");
            pengeluaranPasien(LP, LR);
            getch();
        }
        break;
        }
    }
    while(menu!=0);
}
