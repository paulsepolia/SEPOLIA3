#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    {
        dense_container<double> dc;

        dc.allocate(0);

        std::cout << std::boolalpha;

        std::cout << (dc.size() == 0) << std::endl;
        std::cout << !dc.allocated() << std::endl;
        std::cout << dc.deallocated() << std::endl;

        dc.deallocate();

        std::cout << (dc.size() == 0) << std::endl;
        std::cout << !dc.allocated() << std::endl;
        std::cout << dc.deallocated() << std::endl;
    }

    {
        dense_container<double> dc;

        dc.allocate(100);

        std::cout << std::boolalpha;

        std::cout << (dc.size() == 100) << std::endl;
        std::cout << dc.allocated() << std::endl;
        std::cout << !dc.deallocated() << std::endl;

        dc.deallocate();

        std::cout << (dc.size() == 0) << std::endl;
        std::cout << !dc.allocated() << std::endl;
        std::cout << dc.deallocated() << std::endl;
    }

}
