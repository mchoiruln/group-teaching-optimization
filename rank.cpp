#include "rank.h"
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>

// int RANK(double value, const std::vector<double>& data) {
//     // Salin data ke vektor baru untuk diurutkan
//     std::vector<double> sortedData = data;
//     std::sort(sortedData.begin(), sortedData.end(), std::greater<double>());

//     // Cari posisi value dalam data terurut
//     auto it = std::find(sortedData.begin(), sortedData.end(), value);

//     if (it != sortedData.end()) {
//         // Hitung jumlah nilai yang sama dengan value sebelumnya
//         int count = 0;
//         for (auto jt = sortedData.begin(); jt != it; ++jt) {
//             if (*jt == value) {
//                 ++count;
//             }
//         }

//         // Kembalikan peringkat sebagai posisi value dalam data terurut,
//         // dikurangi jumlah nilai yang sama sebelumnya
//         return std::distance(sortedData.begin(), it) - count + 1;
//     } else {
//         // Jika nilai tidak ditemukan, kembalikan -1
//         return -1;
//     }
// }

int RANK(double value, const std::vector<double>& data) {
    // Hitung jumlah nilai yang lebih besar dari value
    int count = 0;
    for (double val : data) {
        if (val > value) {
            ++count;
        }
    }

    // Kembalikan peringkat sebagai jumlah nilai yang lebih besar ditambah 1
    return count + 1;
}


std::vector<int> computeRanking(const std::vector<double>& data) {
    // Map to store the count of each unique value
    std::map<double, int> valueCount;

    // Count occurrences of each value
    for (double val : data) {
        valueCount[val]++;
    }

    // Vector to store the result
    std::vector<int> ranking(data.size());

    // Calculate ranking for each element
    for (size_t i = 0; i < data.size(); ++i) {
        int rank = 1;
        for (auto it = valueCount.rbegin(); it != valueCount.rend(); ++it) {
            if (it->first == data[i]) {
                break;
            }
            rank += it->second;
        }
        ranking[i] = rank;
    }

    return ranking;
}

std::vector<double> convertToVec(const long double arr[][1000], int rows, int cols) {
    std::vector<double> vec;

    // Iterasi melalui setiap elemen dalam array 2D dan menambahkannya ke vektor
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            vec.push_back(arr[i][j]);
        }
    }
    
    return vec;
}


// Implementasi fungsi printArray2D
void printArray2D(const long double arr[][1000], int rows, int cols, int numRows) {
    std::vector<std::vector<long double>> vec(numRows, std::vector<long double>(cols));
    // Mengonversi array 2D menjadi vektor
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < cols; ++j) {
            vec[i][j] = arr[i][j];
        }
    }
    // Memanggil fungsi printVector untuk mencetak vektor
    printVector(vec);
}

// Implementasi fungsi printVector
template<typename T>
void printVector(const std::vector<std::vector<T>>& vec) {
    for (const auto& row : vec) {
        for (const auto& element : row) {
            // Atur presisi angka menjadi 10 desimal
            std::cout << std::fixed << std::setprecision(10) << element << " ";
        }
        std::cout << std::endl;
    }
}