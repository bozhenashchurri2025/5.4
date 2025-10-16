#include <iostream>
#include "functions.h"

int main() {
    int K, N;
    std::cout << "K = ";
    std::cin >> K;
    std::cout << "N = ";
    std::cin >> N;

    if (K > N) {
        std::cout << "Error: K cannot be greater than N." << std::endl;
        return 1;
    }
    if (K == 0 && N == 0) {
        std::cout << "Error: K and N cannot both be zero (division by zero)." << std::endl;
    }

    std::cout << "(iter) S0 = " << S0(K, N) << std::endl;
    std::cout << "(rec up ++) S1 = " << S1(K, N, K) << std::endl;
    std::cout << "(rec up --) S2 = " << S2(K, N, N) << std::endl;
    std::cout << "(rec down ++) S3 = " << S3(K, N, K, 0) << std::endl;
    std::cout << "(rec down --) S4 = " << S4(K, N, N, 0) << std::endl;

    return 0;
}