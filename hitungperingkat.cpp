#include <iostream>
#include "hitungperingkat.h"

/// @brief Tentukan rank/peringkat dengan urutan terkecil ke terbesar
/// @param rdm sumber data
/// @param rdm2 deretan ranking dari sumber data
/// @param baris total baris
/// @param kolom total kolom
void hitungPeringkatAsc(long double rdm[BARIS][KOLOM], int rdm2[BARIS][KOLOM], int baris, int kolom)
{
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            int peringkat = 1;
            for (int k = 0; k < kolom; k++)
            {
                if (rdm[i][j] > rdm[i][k])
                {
                    peringkat++;
                }
            }
            rdm2[i][j] = peringkat;
        }
    }
}

/// @brief Tentukan rank/peringkat dengan urutan terbesar ke terkecil
/// @param rdm sumber data
/// @param rdm2 deretan ranking dari sumber data
/// @param baris total baris
/// @param kolom total kolom
void hitungPeringkatDesc(long double rdm[BARIS][KOLOM], int rdm2[BARIS][KOLOM], int baris, int kolom)
{

    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            int peringkat = 1;
            for (int k = 0; k < kolom; k++)
            {
                if (rdm[i][j] < rdm[i][k])
                {
                    peringkat++;
                }
            }
            rdm2[i][j] = peringkat;
        }
    }
}
