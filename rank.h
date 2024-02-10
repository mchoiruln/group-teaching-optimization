#ifndef RANK_H
#define RANK_H

#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip> // Untuk mengatur presisi angka


int RANK(double value, const std::vector<double>& data);
std::vector<int> computeRanking(const std::vector<double>& data);
std::vector<double> convertToVec(const long double arr[][1000], int rows, int cols);

// Deklarasi fungsi printArray2D
void printArray2D(const long double arr[][1000], int rows, int cols, int numRows);

// Deklarasi fungsi printVector
template<typename T>
void printVector(const std::vector<std::vector<T>>& vec);

#endif // RANK_H
