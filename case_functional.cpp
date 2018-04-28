#include "case_functional.h"
#include "Pasien.h"
#include "Obat.h"
#include "Relasi.h"

void rataHargaObat(List_relasi LR, List_Obat LO)
{
    // Dibuat oleh Mia Sayida Fatma - 1301164555 - IF-41-08
    address_relasi r;
    string jenisObat;
    int jObat = 0;
    long jHargaObat = 0;
    cout << "Masukkan jenis obat : ";
    cin >> jenisObat;

    if(first_relasi(LR)!=NULL)
    {
        r = first_relasi(LR);
        do
        {
            if(info_Obat(obt(r)).jenisObat == jenisObat)
            {
                jHargaObat = jHargaObat + info_Obat(obt(r)).hargaObat;
                jObat++;
            }
            r = next_relasi(r);
        }
        while(r!=first_relasi(LR));
    }
    if(jObat>0)
    {
        float mean = jHargaObat / jObat;
        cout << "Jenis obat : " << jenisObat << endl;
        cout << "Jumlah banyak obat yang telah dibeli pasien : " << jObat << endl;
        cout << "Jumlah harga obat yang telah dibeli pasien : " << jHargaObat << endl;
        cout << "Rata-rata harga obat : " << mean << endl;
    }
    else
    {
        cout << "Belum ada data" << endl;
    }
}

void pengeluaranPasien(List_pasien LP, List_relasi LR)
{
    // Dibuat oleh Muhammad Mukhtar Dwi Putra - 1301170278 - IF-41-08
    string nama;
    cout << "Masukkan nama pasien : ";
    cin >> nama;
    address_pasien P,Q;

    P = first_pasien(LP);
    while(P!=NULL)
    {
        if(info_pasien(P).nama == nama)
        {
            Q = P;
        }
        P = next_pasien(P);
    }
    long jHarga = 0;;
    if(Q!=NULL)
    {
        address_relasi r = first_relasi(LR);
        if(r!=NULL)
        {
            do
            {
                if(psn(r)==Q)
                {
                    jHarga = jHarga + info_Obat(obt(r)).hargaObat;
                }
                r = next_relasi(r);
            }
            while(r!=first_relasi(LR));
            cout << "Jumlah pengeluaran yang dibayarkan oleh " << info_pasien(Q).nama << " untuk membayar obat : " << endl;
            cout << "  -> " << jHarga << endl ;
        }
    }
    else
    {
        cout << "Nama yang anda masukkan tidak terdaftar." << endl;
    }
}
