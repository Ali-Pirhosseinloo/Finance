#include <iostream>
#include "EuropeanOption.h"
#include "AsianOption.h"
#include "AmericanOption.h"

int main() {
    
    double S = 100.0;  // Option price
    double K = 100.0;  // Strike price
    double r = 0.05;   // Risk-free rate
    double v = 0.2;    // Volatility
    double T = 1.0;    // One year until expiry

    EuropeanOption EU_Option(S, K, r, v, T);
    AsianOption Asian_Option(S, K, r, v, T);
    AmericanOption American_Option(S, K, r, v, T);

    std::cout << "European Call Price:      " << EU_Option.BSM_Call_Price() << std::endl;
    std::cout << "Euroepan Put Price:       " << EU_Option.BSM_Put_Price() << std::endl;

    std::cout << "European Call Price:      " << EU_Option.MC_Call_Price() << std::endl;
    std::cout << "Euroepan Put Price:       " << EU_Option.MC_Put_Price() << std::endl;

    std::cout << "Asian Call Price:     " << Asian_Option.Asian_MC_Call_Price() << std::endl;
    std::cout << "Asian Put Price:     " << Asian_Option.Asian_MC_Put_Price() << std::endl;

    std::cout << "American Call Price:     " << American_Option.BSM_Call_Price() << std::endl;


    std::cout << "Call Delta:      " << EU_Option.Call_Delta() << std::endl;
    std::cout << "Call Gamma:      " << EU_Option.Call_Gamma() << std::endl;
    std::cout << "Call Vega:       " << EU_Option.Call_Vega() << std::endl;
    std::cout << "Call Theta:      " << EU_Option.Call_Theta() << std::endl;
    std::cout << "Call Rho:        " << EU_Option.Call_Rho() << std::endl;
    std::cout  << std::endl;
    std::cout << "Put Delta:       " << EU_Option.Put_Delta() << std::endl;
    std::cout << "Put Gamma:       " << EU_Option.Put_Gamma() << std::endl;
    std::cout << "Put Vega:        " << EU_Option.Put_Vega() << std::endl;
    std::cout << "Put Theta:       " << EU_Option.Put_Theta() << std::endl;
    std::cout << "Put Rho:         " << EU_Option.Put_Rho() << std::endl;
 
    return 0;
}