#include <mypkg/mypkg.hpp>

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n = 10;
    std::vector<double> xs(n, 1.0);
    multiply_by_two(xs.data(), n);

    if (!std::all_of(xs.begin(), xs.end(), [](double x){ return x == 2.0; })) {
        std::cerr << "multiply_by_two failed :(\n";
        return -1;
    }
}