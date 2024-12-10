#include <iostream>
#include "EuropeanOption.h"
#include "AsianOption.h"
#include "AmericanOption.h"

int main() {
    
    double S = 100.0;  // Option price
    double K = 100.0;  // Strike price
    double r = 0.05;   // Risk-free rate
    double v = 0.2;    // Volatility
    double T = 1.0;    // Maturity

    EuropeanOption EU_Option(S, K, r, v, T); // Create an instance of EuropeanOption
    AsianOption Asian_Option(S, K, r, v, T); // Create an instance of AsianOption
    AmericanOption American_Option(S, K, r, v, T); // Create an instance of AmericanOption

    std::cout << "European Call Price BSM:      " << EU_Option.BSM_Call_Price() << std::endl;
    std::cout << "Euroepan Put Price BSM:       " << EU_Option.BSM_Put_Price() << std::endl;
    std::cout  << std::endl;

    std::cout << "European Call Price MC:      " << EU_Option.MC_Call_Price() << std::endl;
    std::cout << "Euroepan Put Price MC:       " << EU_Option.MC_Put_Price() << std::endl;
    std::cout  << std::endl;

    std::cout << "Asian Call Price MC:     " << Asian_Option.Asian_MC_Call_Price() << std::endl;
    std::cout << "Asian Put Price MC:     " << Asian_Option.Asian_MC_Put_Price() << std::endl;
    std::cout  << std::endl;

    std::cout << "American Call Price BSM:     " << American_Option.BSM_Call_Price() << std::endl;
    std::cout << "American Put Price BNT:     " << American_Option.BNT_Put_Price() << std::endl;
    std::cout  << std::endl;


    std::cout << "European Call Delta BSM:      " << EU_Option.Call_Delta_BSM() << std::endl;
    std::cout << "European Call Gamma BSM:      " << EU_Option.Call_Gamma_BSM() << std::endl;
    std::cout << "European Call Vega BSM:       " << EU_Option.Call_Vega_BSM() << std::endl;
    std::cout << "European Call Theta BSM:      " << EU_Option.Call_Theta_BSM() << std::endl;
    std::cout << "European Call Rho BSM:        " << EU_Option.Call_Rho_BSM() << std::endl;
    std::cout  << std::endl;
    std::cout << "European Put Delta BSM:       " << EU_Option.Put_Delta_BSM() << std::endl;
    std::cout << "European Put Gamma BSM:       " << EU_Option.Put_Gamma_BSM() << std::endl;
    std::cout << "European Put Vega BSM:        " << EU_Option.Put_Vega_BSM() << std::endl;
    std::cout << "European Put Theta BSM:       " << EU_Option.Put_Theta_BSM() << std::endl;
    std::cout << "European Put Rho BSM:         " << EU_Option.Put_Rho_BSM() << std::endl;

    std::cout  << std::endl;
    std::cout << "European Call Delta FDM:      " << EU_Option.Call_Delta_FDM() << std::endl;
    std::cout << "European Call Gamma FDM:      " << EU_Option.Call_Gamma_FDM() << std::endl;
    std::cout << "European Call Vega FDM:      " << EU_Option.Call_Vega_FDM() << std::endl;
    std::cout << "European Call Theta FDM:      " << EU_Option.Call_Theta_FDM() << std::endl;
    std::cout << "European Call Rho FDM:      " << EU_Option.Call_Rho_FDM() << std::endl;
    std::cout  << std::endl;
    std::cout << "European Put Delta FDM:      " << EU_Option.Put_Delta_FDM() << std::endl;
    std::cout << "European Put Gamma FDM:      " << EU_Option.Put_Gamma_FDM() << std::endl;
    std::cout << "European Put Vega FDM:      " << EU_Option.Put_Vega_FDM() << std::endl;
    std::cout << "European Put Theta FDM:      " << EU_Option.Put_Theta_FDM() << std::endl;
    std::cout << "European Put Rho FDM:      " << EU_Option.Put_Rho_FDM() << std::endl;

    std::cout  << std::endl;
    std::cout << "American Put Delta FDM:      " << American_Option.American_Put_Delta_FDM() << std::endl;
    std::cout << "American Put Gamma FDM:      " << American_Option.American_Put_Gamma_FDM() << std::endl;
    std::cout << "American Put Vega FDM:      " << American_Option.American_Put_Vega_FDM() << std::endl;
    std::cout << "American Put Theta FDM:      " << American_Option.American_Put_Theta_FDM() << std::endl;
    std::cout << "American Put Rho FDM:      " << American_Option.American_Put_Rho_FDM() << std::endl;

    std::cout  << std::endl;
    std::cout << "Asian Call Delta FDM:      " << Asian_Option.Asian_Call_Delta_FDM() << std::endl;
    std::cout << "Asian Call Gamma FDM:      " << Asian_Option.Asian_Call_Gamma_FDM() << std::endl;
    std::cout << "Asian Call Vega FDM:      " << Asian_Option.Asian_Call_Vega_FDM() << std::endl;
    std::cout << "Asian Call Theta FDM:      " << Asian_Option.Asian_Call_Theta_FDM() << std::endl;
    std::cout << "Asian Call Rho FDM:      " << Asian_Option.Asian_Call_Rho_FDM() << std::endl;
    std::cout  << std::endl;
    std::cout << "Asian Put Delta FDM:      " << Asian_Option.Asian_Put_Delta_FDM() << std::endl;
    std::cout << "Asian Put Gamma FDM:      " << Asian_Option.Asian_Put_Gamma_FDM() << std::endl;
    std::cout << "Asian Put Vega FDM:      " << Asian_Option.Asian_Put_Vega_FDM() << std::endl;
    std::cout << "Asian Put Theta FDM:      " << Asian_Option.Asian_Put_Theta_FDM() << std::endl;
    std::cout << "Asian Put Rho FDM:      " << Asian_Option.Asian_Put_Rho_FDM() << std::endl;

    return 0;
}