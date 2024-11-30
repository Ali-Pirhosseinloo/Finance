#include <iostream>
#include "Option.h"
#include "EuropeanOption.h"
#include "AsianOption.h"
#include "BSM.h"


int main() {
    /*
    double S = 100.0;  // Option price
    double K = 100.0;  // Strike price
    double r = 0.05;   // Risk-free rate
    double v = 0.2;    // Volatility of the underlying
    double T = 1.0;    // One year until expiry

    EuropeanOption Option(S,K,r,v,T);

    double call = Option.MC_Call_Price();
    double put = Option.MC_Put_Price();

    std::cout << "Call Price:      " << call << std::endl;
    std::cout << "Put Price:       " << put << std::endl;
*/

    double S = 30.0;  // Option price
  double K = 29.0;  // Strike price
  double r = 0.08;   // Risk-free rate (8%)
  double v = 0.3;    // Volatility of the underlying (30%)
  double T = 1.00;    

  AsianOption A_Option(S,K,r,v,T);

  std::cout << "Underlying:      " << S << std::endl;
  std::cout << "Strike:          " << K << std::endl;
  std::cout << "Risk-Free Rate:  " << r << std::endl;
  std::cout << "Volatility:      " << v << std::endl;
  std::cout << "Maturity:        " << T << std::endl;

  std::cout << "Asian Price:     " << A_Option.Asian_MC_Put_Price() << std::endl;

    return 0;
}