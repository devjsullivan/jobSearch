#include "interval_map.h"
#include <cstdlib>
#include <random>

#define max(a,b) (a < b) ? b : a

int main() {
    if (__cplusplus == 202101L) std::cout << "C++23";
    else if (__cplusplus == 202002L) std::cout << "C++20";
    else if (__cplusplus == 201703L) std::cout << "C++17";
    else if (__cplusplus == 201402L) std::cout << "C++14";
    else if (__cplusplus == 201103L) std::cout << "C++11";
    else if (__cplusplus == 199711L) std::cout << "C++98";
    else std::cout << "pre-standard C++." << __cplusplus;
    std::cout << "\n";

    for (int mc = 0; mc <= 999; mc++)
    {
        interval_map<double, int> localImap(0);
        std::cout << "size of localImap =" << localImap.m_map.size() << std::endl;
        std::random_device rd;     // Only used once to initialise (seed) engine
        std::mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
        std::uniform_int_distribution<int> uni(-999,999); // Guaranteed unbiased

       auto randB = max(-999.0, uni(rng));
       auto randE = uni(rng);
        localImap.assign(randB, randE, 800);
        std::cout << "size of localImap =" << localImap.m_map.size() << std::endl;

        std::cout << "randB = " << randB << std::endl;
        std::cout << "randE = " << randE << std::endl;
    for(int j = max(randB, -999); j < randE; j++) {
        if (localImap[j] != 800) {
            std::cout << "localImap[j] = " << localImap[j] << std::endl;
            std::cout << "Your code is broke at j = " << j << std::endl;

            std::cout << "************* exiting... ****************************" << std::endl;
            exit(-1);
        }
    }
    std::cout << "Hello, think-cell!" << std::endl;
    std::cout << "val at 1 =" << localImap[1] << std::endl;
    std::cout << "val at 2 =" << localImap[2] << std::endl;
    std::cout << "MC is " << mc << std::endl;
}


    return 0;
}
