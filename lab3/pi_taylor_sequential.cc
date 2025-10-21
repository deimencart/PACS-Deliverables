#include <iomanip>
#include <iostream>
#include <limits>
#include <chrono>


// Allow to change the floating point type
using my_float = long double;

my_float pi_taylor(size_t steps) {
    my_float sum = 0.0f;  
    int sign = 1; 
    for (size_t i = 0; i<steps ; i++) {
        sum += (sign / static_cast <my_float>(2*i+1));
        sign = -sign; 
        std::cout << sum << std::endl;
    }
    //std::cout << sum <<endl;
    return 4.0f*sum;
}

int main(int argc, const char *argv[]) {

    // read the number of steps from the command line
    if (argc != 2) {
        std::cerr << "Invalid syntax: pi_taylor <steps>" << std::endl;
        exit(1);

    }

    size_t steps = std::stoll(argv[1]);
    auto start = std::chrono::system_clock::now();
    auto pi = pi_taylor(steps);

    std::cout << "For " << steps << ", pi value: "
        << std::setprecision(std::numeric_limits<my_float>::digits10 + 1)
        << pi << std::endl;
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<float,std::milli> duration = end - start;

    std::cout<<duration.count()<<“s“<<std::endl;
}
