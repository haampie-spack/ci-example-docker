#include <mypkg/mypkg.hpp>

#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

int main() {
    int n = 10;
    std::vector<double> xs(n, 1.0);
    multiply_by_two(xs.data(), n);
    std::copy(xs.begin(), xs.end(), std::ostream_iterator<double>(std::cout, " "));
    std::cout << '\n';
}