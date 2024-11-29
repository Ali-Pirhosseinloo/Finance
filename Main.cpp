#include <iostream>
#include "BSM.h"

int main() {
    // First we create the parameter list
    double S = 100.0;  // Option price
    double K = 110.0;  // Strike price
    double r = 0.02;   // Risk-free rate
    double v = 0.1;    // Volatility of the underlying
    double T = 1.0;    // One year until expiry

    BSM Option(S,K,r,v,T);

    // Then we calculate the call/put values
    double call = Option.call_BSM_price();
    double put = Option.put_BSM_price();

    // Finally we output the parameters and prices

    std::cout << "Call Price:      " << call << std::endl;
    std::cout << "Put Price:       " << put << std::endl;

    return 0;
}