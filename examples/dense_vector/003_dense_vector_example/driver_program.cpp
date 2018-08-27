#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../sepolia/sepolia.h"

using namespace sepolia;

int main() {

    {
        dense_vector<double> vd;

        vd.allocate(0);

        std::cout << std::boolalpha;

        std::cout << (vd.size() == 0) << std::endl;
        std::cout << !vd.allocated() << std::endl;
        std::cout << vd.deallocated() << std::endl;

        vd.deallocate();

        std::cout << (vd.size() == 0) << std::endl;
        std::cout << !vd.allocated() << std::endl;
        std::cout << vd.deallocated() << std::endl;
    }

    {
        dense_vector<double> vd;

        vd.allocate(100);

        std::cout << std::boolalpha;

        std::cout << (vd.size() == 100) << std::endl;
        std::cout << vd.allocated() << std::endl;
        std::cout << !vd.deallocated() << std::endl;

        vd.deallocate();

        std::cout << (vd.size() == 0) << std::endl;
        std::cout << !vd.allocated() << std::endl;
        std::cout << vd.deallocated() << std::endl;
    }
}
