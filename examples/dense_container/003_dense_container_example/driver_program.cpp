#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    {
        dense_container<double> dcon;

        dcon.allocate(0);

        std::cout << std::boolalpha;

        std::cout << (dcon.size() == 0) << std::endl;
        std::cout << !dcon.allocated() << std::endl;
        std::cout << dcon.deallocated() << std::endl;

        dcon.deallocate();

        std::cout << (dcon.size() == 0) << std::endl;
        std::cout << !dcon.allocated() << std::endl;
        std::cout << dcon.deallocated() << std::endl;
    }

    {
        dense_container<double> dcon;

        dcon.allocate(100);

        std::cout << std::boolalpha;

        std::cout << (dcon.size() == 100) << std::endl;
        std::cout << dcon.allocated() << std::endl;
        std::cout << !dcon.deallocated() << std::endl;

        dcon.deallocate();

        std::cout << (dcon.size() == 0) << std::endl;
        std::cout << !dcon.allocated() << std::endl;
        std::cout << dcon.deallocated() << std::endl;
    }

}
