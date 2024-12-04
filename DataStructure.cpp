#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>

double linearMinSearch(const std::vector<double>& data) {
    if (data.empty()) {
        return 0.0;
    }
    double minValue = data[0];
    for (const double& val : data) {
        if (val < minValue) {
            minValue = val;
        }
    }
    return minValue;
}

int main() {
    const int N = 1000000;
    std::vector<double> data(N);
    std::srand(42);
    for (int i = 0; i < N; ++i) {
        data[i] = std::rand() / static_cast<double>(RAND_MAX);
    }

    {
        auto start = std::chrono::high_resolution_clock::now();
        double minVal = linearMinSearch(data);
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Linear search time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;
    }

    {
        auto start = std::chrono::high_resolution_clock::now();
        double minVal = *std::min_element(data.begin(), data.end());
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "std::min_element time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;
    }
    return 0;
}