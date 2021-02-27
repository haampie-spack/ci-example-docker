#include <mypkg/mypkg.hpp>

#include <iostream>

int main() {
    if (compute_something() != 0.0) {
        std::cerr << "compute_somthing() != 0.0\n";
        return -1;
    }
}