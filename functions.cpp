#include "functions.h"
#include <cmath>

double S0(const int K, const int N) {
    double s = 0;
    double denominator = 1.0 * K * K + 1.0 * N * N;
    if (denominator == 0) return 0;

    for (int i = K; i <= N; i++) {
        s += (1.0 * i * i) / denominator;
    }
    return s;
}

double S1(const int K, const int N, const int i) {
    if (i > N) {
        return 0;
    } else {
        double denominator = 1.0 * K * K + 1.0 * N * N;
        if (denominator == 0) return 0;
        return (1.0 * i * i) / denominator + S1(K, N, i + 1);
    }
}

double S2(const int K, const int N, const int i) {
    if (i < K) {
        return 0;
    } else {
        double denominator = 1.0 * K * K + 1.0 * N * N;
        if (denominator == 0) return 0;
        return (1.0 * i * i) / denominator + S2(K, N, i - 1);
    }
}

double S3(const int K, const int N, const int i, double t) {
    double denominator = 1.0 * K * K + 1.0 * N * N;
    if (denominator == 0) return t;

    t = t + (1.0 * i * i) / denominator;
    if (i >= N) {
        return t;
    } else {
        return S3(K, N, i + 1, t);
    }
}

double S4(const int K, const int N, const int i, double t) {
    double denominator = 1.0 * K * K + 1.0 * N * N;
    if (denominator == 0) return t;

    t = t + (1.0 * i * i) / denominator;
    if (i <= K) {
        return t;
    } else {
        return S4(K, N, i - 1, t);
    }
}