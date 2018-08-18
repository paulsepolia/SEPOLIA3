#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../vector_dense/vector_dense.h"

using sepolia::vector_dense;

int main() {

    {
        vector_dense<double> vd;

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
        vector_dense<double> vd;

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
