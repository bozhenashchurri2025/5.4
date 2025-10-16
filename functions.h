#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Ітеративна функція
double S0(const int K, const int N);

// Рекурсивна функція (зростання індексу)
double S1(const int K, const int N, const int i);

// Рекурсивна функція (спадання індексу)
double S2(const int K, const int N, const int i);

// Хвостова рекурсія (зростання індексу)
double S3(const int K, const int N, const int i, double t);

// Хвостова рекурсія (спадання індексу)
double S4(const int K, const int N, const int i, double t);

#endif //FUNCTIONS_H