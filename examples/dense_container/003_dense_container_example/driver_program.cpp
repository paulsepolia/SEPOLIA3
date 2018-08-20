#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    {
        dense_container<double> vd;

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
        dense_container<double> vd;

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
