#include <iostream>
#include <conio.h>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <cstring>
#include <ostream>
#include <strstream>
#include <vector>

using namespace std;

int i, j, k, salah, pilih, cek, datajarak[1000][1000], datapd[1000][1000], pelanggan, kapasitas, kap_awal, nmurid, nmurid1, maxiter, maxiter1, x[1000][1000], ftujuan[1000], iterasi = 1, T[1000][1000], ftujuan_T[1000], prestasi, rata, xguru[1000][1000], ftujuan_xguru[1000], urutan[1000], best, batas, xmurid[1000][1000], ftujuan_xmurid[1000];

long double xr[1000][1000], Tr[1000][1000], xgurur[1000][1000], M[1000][1000], xmuridr[1000][1000];
char st[1000];
void InputData();
void InisialisasiParameter();
void BangkitMurid(long double rdm[1000][1000]);
void FungsiTujuan(long double rdm[1000][1000], int rdm2[1000][1000], int findiv[1000], int awal, int akhir);
int SolusiTerbaik(long double rdm[1000][1000], int rdm2[1000], int findiv[1000]);
void PengalokasianGuru(int rdm[1000], long double rdm2[1000][1000], long double rdm3[1000][1000], int findiv[1000], int findiv2[1000], int index);
void PengelompokkanKemampuan(int rdm[1000]);
void FaseGuru1(long double rdm[1000][1000], long double rdm2[1000][1000], int rdm3[1000], long double rdm4[1000][1000], int findiv[1000], int findiv2[1000]);
void FaseGuru2(long double rdm[1000][1000], long double rdm2[1000][1000], int rdm3[1000], long double rdm4[1000][1000], int findiv[1000], int findiv2[1000]);
void FaseMurid(long double rdm[1000][1000], long double rdm2[1000][1000], long double rdm3[1000][1000], int findiv[1000], int findiv2[1000], int findiv3[1000]);

// Variabel Lainnya
int pilihan1, pilihan0, pilihan, pilihan2, benarr, HASIL;
char jawab[5], file[50], nama[50], namafile[50];

ofstream VRPSPD;

int main()
{
    ifstream datajarak1, datapd1;
    cout << "=====================================================";
    cout << "\n Penerapan Group Teaching Optimization Algorithm untuk menyelesaikan";
    cout << "\n Vehicle Routing Problem with Simultaneous Pickup and Delivery ";
    cout << "\n Iktysha Andiny (081911233046) ";
    cout << "\n===================================================" << endl;
    cout << " Pilihan Data : ";
    cout << "\n 1. Data Kecil";
    cout << "\n 2. Data Sedang";
    cout << "\n 3. Data Besar";
    
    do
    {
        cout << "\nPilihan : ";
        cin >> pilihan1;
        // pilihan1=2;
        pilihan0 = pilihan1;
        pilihan = pilihan1;
        pilihan2 = pilihan1 - pilihan;
        switch (pilihan)
        {
        case 1:
            cout << "\nPilihan : " << pilihan << endl;
            datajarak1.open("Data/jarak_kecil.txt");
            datapd1.open("Data/pd_kecil.txt");
            benarr = 1;
            pelanggan = 13;
            kapasitas = 180;
            break;
        case 2:
            datajarak1.open("Data/jarak_sedang.txt");
            datapd1.open("Data/pd_sedang.txt");
            benarr = 1;
            pelanggan = 22;
            kapasitas = 10500;
            break;
        case 3:
            datajarak1.open("Data/jarak_besar.txt");
            datapd1.open("Data/pd_besar.txt");
            benarr = 1;
            pelanggan = 100;
            kapasitas = 700;
            break;
            break;
        default:
            cout << "Input yang Anda Masukkan Salah, Masukkan Input Lainnya" << endl;
            benarr = 0;
        }
        for (i = 0; i <= pelanggan; i++)
        {
            for (j = 0; j < pelanggan + 1; j++)
            {
                if (pilihan1 == 1 || pilihan1 == 2 || pilihan1 == 3)
                {
                    datajarak1 >> datajarak[i][j];
                }
            }
        }
        for (i = 0; i <= pelanggan; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (pilihan1 == 1 || pilihan1 == 2 || pilihan1 == 3)
                {
                    datapd1 >> datapd[i][j];
                }
            }
        }
    } while (benarr != 1 || pilihan2 != 0 || pilihan1 != pilihan0);
    InisialisasiParameter();
    BangkitMurid(xr);
    FungsiTujuan(xr, x, ftujuan, 0, nmurid);

    do
    {
        best = SolusiTerbaik(xr, urutan, ftujuan);
        PengalokasianGuru(urutan, xr, Tr, ftujuan, ftujuan_T, best);
        PengelompokkanKemampuan(urutan);
        FaseGuru1(xr, xgurur, urutan, Tr, ftujuan, ftujuan_xguru);
        FaseGuru2(xr, xgurur, urutan, Tr, ftujuan, ftujuan_xguru);
        FaseMurid(xr, xgurur, xmuridr, ftujuan, ftujuan_xguru, ftujuan_xmurid);
        iterasi++;
    } while (iterasi <= maxiter);

    getch();
}
void InputData()
{
    int i, j, k;

    ifstream datajarak1, datapd1;
}
void InisialisasiParameter()
{
    do
    {
        salah = 1;
        cout << "Masukkan jumlah murid  : ";
        cin >> st;
        istrstream penampung(st, sizeof(st));
        penampung >> pilih;
        if (!penampung.fail())
        {
            cek = pilih;
            if (cek == pilih && cek > 1)
            {
                salah = 0;
                nmurid = pilih;
            }
            else
            {
                cout << "Masukkan bilangan bulat >1!" << endl;
            }
        }
        else
        {
            cout << "Masukkan bilangan bulat >1!" << endl;
        }

    } while (salah == 1);
    do
    {
        salah = 1;
        cout << "Masukkan jumlah maksimum iterasi  : ";
        cin >> st;
        istrstream penampung(st, sizeof(st));
        penampung >> pilih;
        if (!penampung.fail())
        {
            cek = pilih;
            if (cek == pilih && cek > 0)
            {
                salah = 0;
                maxiter = pilih;
            }
            else
            {
                cout << "Masukkan bilangan bulat >0!" << endl;
            }
        }
        else
        {
            cout << "Masukkan bilangan bulat >0!" << endl;
        }

    } while (salah == 1);
    kap_awal = 0.8 * kapasitas;
    cout << "----------------------------------------" << endl
         << endl;
    cout << "Nama File: ";
    cin >> file;
    cout << "Nomer Urut File : ";
    cin >> HASIL;
    cout << endl;

    // Output Notepad
    strcat(file, " ke- ");    // Menambah Karakter ke Variabel
    strcpy(namafile, file);   // Mengcopy Isi File ke Variabel "namafile"
    itoa(HASIL, nama, 10);    // Misal Diinputkan "HASIL" = 1234, Maka Membuat Nama "1234"
    strcat(namafile, nama);   // Menambah Karakter Nama ke Variabel "namafile"
    strcat(namafile, ".txt"); // Strcat untuk Menggabungkan 2 Buah String (Melakukan Penggabungan Variabel "namafile" dan ".txt")
    cout << namafile << endl << endl;
    // Directory output harus ada!
    std::string filePath = "output/"; 
    filePath += namafile;
    cout << "File berhasil dibuat di " << filePath << endl;
    VRPSPD.open(filePath);
    VRPSPD << "=====================================================";
    VRPSPD << "\n Penerapan Group Teaching Optimization Algorithm untuk menyelesaikan";
    VRPSPD << "\n Vehicle Routing Problem with Simultaneous Pickup and Delivery ";
    VRPSPD << "\n Iktysha Andiny (081911233046) ";
    VRPSPD << "\n===================================================" << endl;
    // Data Jarak
    VRPSPD << "Data Jarak" << endl;
    for (i = 0; i <= pelanggan; i++)
    {
        for (j = 0; j < pelanggan + 1; j++)
        {
            VRPSPD << datajarak[i][j] << " ";
        }
        VRPSPD << endl;
    }
    // Data PD
    VRPSPD << "Data PD" << endl;
    for (i = 0; i <= pelanggan; i++)
    {
        for (j = 0; j < 2; j++)
        {
            VRPSPD << datapd[i][j] << " ";
        }
        VRPSPD << endl;
    }
}
void BangkitMurid(long double rdm[1000][1000])
{
    int i, j;

    vector<vector<long double>> bm = {
        {0.29, 0.85, 0.55, 0.44, 0.43, 0.69, 0.22, 0.48, 0.16, 0.59, 0.29, 0.98, 0.64},
        {0.48, 0.35, 0.66, 0.89, 0.73, 0.52, 0.01, 0.51, 0.44, 0.02, 0.50, 0.39, 0.34},
        {0.57, 0.80, 0.69, 0.56, 0.03, 0.93, 0.52, 0.33, 0.71, 0.15, 0.73, 0.03, 0.37},
        {0.39, 0.20, 0.02, 0.04, 0.85, 0.55, 0.04, 0.13, 0.22, 0.13, 0.88, 0.95, 0.44}
    };

    VRPSPD << "\n\t--- BANGKIT MURID ---";
    for (i = 0; i < nmurid; i++)
    {
        VRPSPD << "\n\tmurid" << i + 1 << "\t";
        for (j = 0; j < pelanggan; j++)
        {
            rdm[i][j] = bm[i][j];
            // (rand() % 10000) * 0.0001;
            VRPSPD << rdm[i][j] << "\t";
        }
        VRPSPD << "\n";
    }
}
void FungsiTujuan(long double rdm[1000][1000], int rdm2[1000][1000], int findiv[1000], int awal, int akhir)
{
    VRPSPD << "\n\t--- FUNGSI TUJUAN ---";
    VRPSPD << "\n\t Pengurutan";
    // Pengurutan
    int i, j, k;
    int spot = awal;
    do
    {
        for (i = 0; i < pelanggan; i++)
        {
            int simpan = 0;
            for (j = 0; j < pelanggan; j++)
            {
                if (rdm[spot][i] > rdm[spot][j])
                {
                    simpan++;
                }
                rdm2[spot][i] = simpan;
            }
        }
        spot++;
    } while (spot < akhir);
     // Mencetak array ke console
    VRPSPD << "\n";
    for (i = awal; i < akhir; i++)
    {
        VRPSPD << "\tmurid" << i + 1 << "\t";
        for (j = 0; j < pelanggan; j++)
        {
            VRPSPD << rdm2[i][j] + 1 << "-";
        }
        VRPSPD << endl;
    }

    // Rute
    int
        permintaan,
        beban, hitung_titik, rute_tempuh[500][25][20], jumlah_rute[300], banyak_titik[300][300];

    for (i = awal; i < akhir; i++)
    {
        jumlah_rute[i] = 0;
    }
    for (i = 0; i < 300; i++)
    {
        for (j = 0; j < 10; j++)
        {
            for (k = 0; k < 50; k++)
            {
                rute_tempuh[i][j][k] = 0;
            }
        }
    }
    for (i = awal; i < akhir; i++)
    {
        // VRPSPD<<"\n\tx"<<i+1<<"\t";
        permintaan = kap_awal;
        beban = kap_awal;
        rute_tempuh[i][jumlah_rute[i]][0] = 0;
        hitung_titik = 0;
        for (j = 0; j < pelanggan; j++)
        {
            permintaan = permintaan - datapd[rdm2[i][j] + 1][0];
            beban = beban - datapd[rdm2[i][j] + 1][0] + datapd[rdm2[i][j] + 1][1];
            hitung_titik++;
            // banyak_titik[i][jumlah_rute[i]]=hitung_titik;
            rute_tempuh[i][jumlah_rute[i]][hitung_titik] = rdm2[i][j] + 1;
            // VRPSPD<<rute_tempuh[i][jumlah_rute[i]][hitung_titik]<<"-";
            if (pelanggan - j != 1)
            {
                if (permintaan < datapd[rdm2[i][j + 1] + 1][0] || beban - datapd[rdm2[i][j + 1] + 1][0] + datapd[rdm2[i][j + 1] + 1][1] > kapasitas)
                {
                    // VRPSPD<<" --> berhenti permintaan: "<<permintaan<<" dan beban: "<<beban<<" serta data: "<<datapd[rdm2[i][j+1]+1][0]<<" --> "<<rdm2[i][j+1]+1<<"\n";
                    rute_tempuh[i][jumlah_rute[i]][hitung_titik] = rdm2[i][j] + 1;
                    hitung_titik++;
                    banyak_titik[i][jumlah_rute[i]] = hitung_titik;
                    rute_tempuh[i][jumlah_rute[i]][hitung_titik] = 0;
                    hitung_titik = 0;
                    jumlah_rute[i]++;
                    rute_tempuh[i][jumlah_rute[i]][0] = 0;
                    // rute_tempuh[i][jumlah_rute[i]][hitung_titik]=rdm2[i][j]+1;
                    permintaan = kap_awal;
                    beban = kap_awal;
                    VRPSPD << "\t\t";
                }
            }
            else if (pelanggan - j == 1)
            {
                hitung_titik++;
                banyak_titik[i][jumlah_rute[i]] = hitung_titik;
                rute_tempuh[i][jumlah_rute[i]][hitung_titik] = 0;
                // goto langsung;
            }
            // VRPSPD<<rute_tempuh[i][jumlah_rute[i]][hitung_titik]<<"-";
        }
    }
    // Hitung Jarak
    int jarak_rute[300][300], a, b;

    // VRPSPD<<"\n\tHitung Jarak";
    for (i = awal; i < akhir; i++)
    {
        // VRPSPD<<"\nRat"<<i+1<<"\t";
        for (j = 0; j <= jumlah_rute[i]; j++)
        {
            // vrp<<"\trute"<<j+1<<" memiliki jarak: ";
            jarak_rute[i][j] = 0;
            for (k = 0; k <= banyak_titik[i][j]; k++)
            {
                a = rute_tempuh[i][j][k];
                b = rute_tempuh[i][j][k + 1];
                // VRPSPD<<a<<"\t";
                jarak_rute[i][j] = jarak_rute[i][j] + datajarak[a][b];
            }
            // VRPSPD<<jarak_rute[i][j]<<"\t";
        }
    }
    VRPSPD << "\n\tRute dan Jarak\n";
    for (i = awal; i < akhir; i++)
    {
        findiv[i] = 0;
        VRPSPD << "\tmurid" << i + 1 << " ";
        for (j = 0; j <= jumlah_rute[i]; j++)
        {
            VRPSPD << "\n\tRute[" << j + 1 << "]\t";
            findiv[i] = findiv[i] + jarak_rute[i][j];
            for (k = 0; k <= banyak_titik[i][j]; k++)
            {
                VRPSPD << rute_tempuh[i][j][k] << "--";
            }
            VRPSPD << "\t dengan jarak: " << jarak_rute[i][j];
        }
        VRPSPD << "\n\tFungsi tujuan murid" << i + 1 << ": " << findiv[i] << "\n\n";
    }
}
int SolusiTerbaik(long double rdm[1000][1000], int rdm2[1000], int findiv[1000])
{
    int i, j, k, tunjuk;
    int spot = 0;
    VRPSPD << "\n\t--- SOLUSI TERBAIK ---";
    for (i = 0; i < nmurid; i++)
    {
        int simpan = 0;
        for (j = 0; j < nmurid; j++)
        {
            if (findiv[i] > findiv[j])
            {
                simpan++;
            }
            rdm2[i] = simpan;
        }
    }
    for (i = 0; i < nmurid; i++)
    {
        VRPSPD << "\n\tx" << i + 1 << "\t" << rdm2[i];
        if (rdm2[i] == 0)
        {
            tunjuk = i;
            VRPSPD << "\t--> terbaik sementara " << tunjuk + 1;
        }
    }
    return tunjuk;
}
void PengalokasianGuru(int rdm[1000], long double rdm2[1000][1000], long double rdm3[1000][1000], int findiv[1000], int findiv2[1000], int index)
{
    VRPSPD << "\n\n\t--- FASE PENGALOKASIAN GURU ---\n";
    int i, j, k;
    long double jumlah[300];
    VRPSPD << "\tMenghitung rata rata 3 murid terbaik\n";
    for (i = 0; i < pelanggan; i++)
    {
        jumlah[i] = 0;
    }
    int spot = 0;
    do
    {
        for (i = 0; i < 3; i++)
        {
            if (rdm[spot] == i)
            {
                for (j = 0; j < pelanggan; j++)
                {
                    jumlah[j] = jumlah[j] + rdm2[spot][j];
                    rdm3[iterasi][j] = jumlah[j] / 3;
                }
            }
        }
        spot++;
    } while (spot < nmurid);
    VRPSPD << "\tx" << iterasi << "g\t";
    for (i = 0; i < pelanggan; i++)
    {
        VRPSPD << setprecision(4) << rdm3[iterasi][i] << "\t";
    }
    FungsiTujuan(rdm3, T, findiv2, iterasi, iterasi + 1);
    VRPSPD << "\tPenentuan Guru";
    if (findiv[index] < findiv2[iterasi])
    {
        VRPSPD << "\n\tf(x" << index + 1 << ") " << findiv[index] << " < " << findiv2[iterasi] << " f(x" << iterasi << "g)";
        VRPSPD << "\n\tMurid" << index + 1 << " yang menjadi guru\n\t";
        findiv2[iterasi] = findiv[index];
        for (i = 0; i < pelanggan; i++)
        {
            rdm3[iterasi][i] = rdm2[index][i];
        }
    }
    else
    {
        VRPSPD << "\n\tftujuan murid terbaik " << findiv[index] << " > " << findiv2[iterasi] << "ftujuan x" << iterasi << "g";
        VRPSPD << "\n\tx" << iterasi << "g yang menjadi guru\n\t";
    }
    for (i = 0; i < pelanggan; i++)
    {
        VRPSPD << setprecision(4) << rdm3[iterasi][i] << "\t";
    }
    VRPSPD << "\n\tFungsi Tujuan: " << findiv2[iterasi] << "\n";
}
void PengelompokkanKemampuan(int rdm[1000])
{
    int i, j;
    if (nmurid % 2 == 0)
    {
        prestasi = nmurid / 2; // batas=nmurid/2;
        rata = nmurid / 2;
    }
    else
    {
        prestasi = (nmurid + 1) / 2; // batas=prestasi
        rata = nmurid - prestasi;
    }
    VRPSPD << "\n\t--- FASE PENGELOMPOKKAN KEMAMPUAN ---";
    VRPSPD << "\n\tTerdapat " << prestasi << " murid berprestasi dan " << rata << " murid dengan kemampuan rata rata\n";
    for (i = 0; i < nmurid; i++)
    {
        VRPSPD << "\n\tx" << i + 1 << "\t";
        if (rdm[i] < prestasi)
        {
            VRPSPD << "--> berprestasi (P0)";
        }
        if (rdm[i] >= prestasi)
        {
            VRPSPD << "--> rata- rata (Pa)";
        }
    }
}
void FaseGuru1(long double rdm[1000][1000], long double rdm2[1000][1000], int rdm3[1000], long double rdm4[1000][1000], int findiv[1000], int findiv2[1000])
{
    int i, j, k, F;
    float a, b, c, m[300][100], jumlah[300];
    VRPSPD << "\n\n\t--- FASE GURU I ---";
    VRPSPD << "\n\t(untuk murid berprestasi)";
    VRPSPD << "\n\tNilai Acak";
    a = (rand() % 1000) * 0.001;
    b = (rand() % 1000) * 0.001;
    c = 1 - b;
    F = (rand() % 2) + 1;
    VRPSPD << "\n\ta:" << a << "\t\tF: " << F;
    VRPSPD << "\n\tb:" << b;
    VRPSPD << "\n\tc:" << c;
    VRPSPD << "\n\n\tPengetahuan rata-rata kelompok\n\t";
    for (i = 0; i < pelanggan; i++)
    {
        jumlah[i] = 0;
    }
    for (i = 0; i < nmurid; i++)
    {
        // VRPSPD<<"\tx"<<i+1<<"\t";
        for (j = 0; j < pelanggan; j++)
        {
            jumlah[j] = jumlah[j] + rdm[i][j];
            M[iterasi][j] = jumlah[j] / nmurid;
            // VRPSPD<<M[iterasi][j]<<"\t";
        } // VRPSPD<<"\n";
    }
    for (i = 0; i < pelanggan; i++)
    {
        VRPSPD << setprecision(4) << M[iterasi][i] << "\t";
    }
    VRPSPD << "\n\n\tMenghitung nilai pengetahuan murid\n";
    for (i = 0; i < nmurid; i++)
    {
        if (rdm3[i] < prestasi)
        {
            VRPSPD << "\tx" << i + 1 << "\t";
            for (j = 0; j < pelanggan; j++)
            {
                rdm2[i][j] = rdm[i][j] + a * (rdm4[iterasi][j] - F * ((b * M[iterasi][j]) + (c * rdm[i][j])));
                VRPSPD << setprecision(4) << rdm2[i][j] << "\t";
            }
            VRPSPD << "\n";
            FungsiTujuan(rdm2, xguru, findiv2, i, i + 1);
        }
    }
    VRPSPD << "\n\tMembandingkan x dengan xguru\n";
    VRPSPD << "\t\tFtujuan x\tFtujuan xguru\n";
    for (i = 0; i < nmurid; i++)
    {
        if (rdm3[i] < prestasi)
        {
            VRPSPD << "\t" << i + 1 << "\t";
            VRPSPD << findiv[i] << "\t\t" << findiv2[i];
            if (findiv[i] >= findiv2[i])
            {
                VRPSPD << "\t--> diperbarui";
                // findiv[i]=findiv2[i];
                for (j = 0; j < pelanggan; j++)
                {
                    // rdm[i][j]=rdm2[i][j];
                }
            }
            else if (findiv[i] < findiv2[i])
            {
                VRPSPD << "\t--> ditolak";
            }
            VRPSPD << "\n";
        }
    }
    /*VRPSPD<<"\n\tCek Populasi\n";
    for(i=0;i<nmurid;i++){
        VRPSPD<<"\tx"<<i+1<<"\t";
        for(j=0;j<pelanggan;j++){
            VRPSPD<<rdm2[i][j]<<"\t";
        }VRPSPD<<"\n";
    }*/
}
void FaseGuru2(long double rdm[1000][1000], long double rdm2[1000][1000], int rdm3[1000], long double rdm4[1000][1000], int findiv[1000], int findiv2[1000])
{
    int i, j, k;
    float d;
    VRPSPD << "\n\t--- FASE GURU II ---";
    VRPSPD << "\n\t(untuk murid rata-rata)";
    VRPSPD << "\n\tNilai Acak";
    d = (rand() % 1000) * 0.001;
    VRPSPD << "\n\td:" << d;
    VRPSPD << "\n\n\tMenghitung nilai pengetahuan murid\n";
    for (i = 0; i < nmurid; i++)
    {
        if (rdm3[i] >= prestasi)
        {
            VRPSPD << "\tx" << i + 1 << "\t";
            for (j = 0; j < pelanggan; j++)
            {
                rdm2[i][j] = rdm[i][j] + 2 * d * (rdm4[iterasi][j] - rdm[i][j]);
                VRPSPD << setprecision(4) << rdm2[i][j] << "\t";
            }
            VRPSPD << "\n";
            FungsiTujuan(rdm2, xguru, findiv2, i, i + 1);
        }
    }
    VRPSPD << "\n\tMembandingkan x dengan xguru\n";
    VRPSPD << "\t\tFtujuan x\tFtujuan xguru\n";
    for (i = 0; i < nmurid; i++)
    {
        if (rdm3[i] >= prestasi)
        {
            VRPSPD << "\t" << i + 1 << "\t";
            VRPSPD << findiv[i] << "\t\t" << findiv2[i];
            if (findiv[i] >= findiv2[i])
            {
                VRPSPD << "\t--> diperbarui";
                // findiv[i]=findiv2[i];
                for (j = 0; j < pelanggan; j++)
                {
                    // rdm[i][j]=rdm2[i][j];
                }
            }
            else if (findiv[i] < findiv2[i])
            {
                VRPSPD << "\t--> ditolak";
            }
            VRPSPD << "\n";
        }
    }
    /*VRPSPD<<"\n\tCek Populasi\n";
    for(i=0;i<nmurid;i++){
        VRPSPD<<"\tx"<<i+1<<"\t";
        for(j=0;j<pelanggan;j++){
            VRPSPD<<rdm2[i][j]<<"\t";
        }VRPSPD<<"\n";
    }*/
}
void FaseMurid(long double rdm[1000][1000], long double rdm2[1000][1000], long double rdm3[1000][1000], int findiv[1000], int findiv2[1000], int findiv3[1000])
{
    int i, j, k, match[300];
    float e, g;

    VRPSPD << "\n\t--- FASE MURID ---";
    VRPSPD << "\n\tNilai Acak";
    e = (rand() % 1000) * 0.001;
    g = (rand() % 1000) * 0.001;
    VRPSPD << "\n\te:" << e;
    VRPSPD << "\n\tg:" << g;

    VRPSPD << "\n\n\tMenentukan Pasangan Murid\n";
    VRPSPD << "\txi\txj\n";

    for (i = 0; i < nmurid; i++)
    {
        VRPSPD << "\t" << i + 1 << "\t";
        match[i] = (rand() % nmurid);
        VRPSPD << match[i] + 1 << "\n";
    }
    VRPSPD << "\n\tInteraksi Murid\n";
    for (i = 0; i < nmurid; i++)
    {
        VRPSPD << "\tx" << i + 1 << " dengan x" << match[i] + 1 << "\n";
        if (findiv2[i] < findiv2[match[i]])
        {
            VRPSPD << "\tf(x" << i + 1 << ") " << findiv2[i] << " < " << findiv2[match[i]] << " f(x" << match[i] + 1 << ")\t--> menggunakan rumus 2.10a\n";
            VRPSPD << "\tx" << iterasi << ", murid" << i + 1 << "\n\t";
            for (j = 0; j < pelanggan; j++)
            {
                rdm3[i][j] = rdm2[i][j] + e * (rdm2[i][j] - rdm2[match[i]][j]) + g * (rdm2[i][j] - rdm[i][j]);
                VRPSPD << rdm3[i][j] << "\t";
            }
        }
        else if (findiv2[i] >= findiv2[match[i]])
        {
            VRPSPD << "\tf(x" << i + 1 << ") " << findiv2[i] << " >= " << findiv2[match[i]] << " f(x" << match[i] + 1 << ")\t--> menggunakan rumus 2.10b\n";
            VRPSPD << "\tx" << iterasi << ", murid" << i + 1 << "\n\t";
            for (j = 0; j < pelanggan; j++)
            {
                rdm3[i][j] = rdm2[i][j] - e * (rdm2[i][j] - rdm2[match[i]][j]) + g * (rdm2[i][j] - rdm[i][j]);
                VRPSPD << rdm3[i][j] << "\t";
            }
        }
        FungsiTujuan(rdm3, xmurid, findiv3, i, i + 1);
        VRPSPD << "\t==================================================\n";
    }
    VRPSPD << "\n\tMembandingkan xguru dengan xmurid\n";
    VRPSPD << "\t\tFtujuan xguru\tFtujuan xmurid\n";
    for (i = 0; i < nmurid; i++)
    {
        VRPSPD << "\t" << i + 1 << "\t";
        VRPSPD << findiv2[i] << "\t\t" << findiv3[i];
        if (findiv2[i] < findiv3[i])
        {
            VRPSPD << "\t--> ditolak";
            findiv[i] = findiv2[i];
            for (j = 0; j < pelanggan; j++)
            {
                rdm[i][j] = rdm2[i][j];
            }
        }
        else if (findiv2[i] >= findiv3[i])
        {
            VRPSPD << "\t--> diperbarui";
            findiv[i] = findiv3[i];
            for (j = 0; j < pelanggan; j++)
            {
                rdm[i][j] = rdm3[i][j];
            }
        }
        VRPSPD << "\n";
    }
    VRPSPD << "\n\tPopulasi Baru\n";
    for (i = 0; i < nmurid; i++)
    {
        VRPSPD << "\tx" << i + 1 << "\t";
        for (j = 0; j < pelanggan; j++)
        {
            VRPSPD << rdm[i][j] << "\t";
        }
        VRPSPD << " dengan ftujuan: " << ftujuan[i] << "\n";
    }
    // FaseMurid(xr, xgurur, xmuridr, ftujuan, ftujuan_xguru, ftujuan_xmurid);
}
