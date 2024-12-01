#include <cmath>
#include <algorithm>
#include "Option.h"
#include "NormRand_Gen.h"


Option::Option (const double& _S, const double& _K,const double& _r, const double& _v, const double& _T): 
        S(_S), 
        K(_K),
        r(_r),
        v(_v),
        T(_T)
        {}


    double Option::MC_Call_Price(int num_simulations) const {

        double sum_payoffs = 0.0;

        for (int i = 0; i < num_simulations; ++i) {

            double simulated_price = S * std::exp(T * (r - 0.5 * v * v) + v * std::sqrt(T) * Normal_Rand());

            sum_payoffs += Call_PayOff(simulated_price);
        }

        return (std::exp(- r * T) * sum_payoffs) / num_simulations;
    }



        double Option::MC_Put_Price(int num_simulations) const {

        double sum_payoffs = 0.0;

        for (int i = 0; i < num_simulations; ++i) {

            double simulated_price = S * std::exp(T * (r - 0.5 * v * v) + v * std::sqrt(T) * Normal_Rand());

            sum_payoffs += Put_PayOff(simulated_price);
        }

        return (std::exp(- r * T) * sum_payoffs) / num_simulations;
    }


////////////////////////////////////////////////////////////

double Option::d_plus() {
return (log(S/K) + (r + 0.5 * v * v) * T) / (v * (pow(T,0.5)));
}

double Option::d_minus() {
return (log(S/K) + (r - 0.5 * v * v) * T) / (v * (pow(T,0.5)));
}

////////////////////////////////////////////////////////////

double Option::BSM_Call_Price() {
return S * Normal_CDF(d_plus())-K * exp(- r * T) * Normal_CDF(d_minus());
}

double Option::BSM_Put_Price() {
return -S * Normal_CDF(-d_plus()) + K * exp(- r * T) * Normal_CDF(-d_minus());
}

////////////////////////////////////////////////////////////

double Option::Call_Delta() {
  return Normal_CDF(d_plus());
}

double Option::Call_Gamma() {
  return Normal_PDF(d_plus())/(S * v * sqrt(T));
}

double Option::Call_Vega() {
  return S * Normal_PDF(d_plus()) * sqrt(T);
}

double Option::Call_Theta() {
  return -(S * Normal_PDF(d_plus()) * v)/(2 * sqrt(T)) 
    - r * K * exp(-r * T) * Normal_CDF(d_minus());
}

double Option::Call_Rho() {
  return K * T * exp(-r * T) * Normal_CDF(d_minus());
}

////////////////////////////////////////////////////////////

double Option::Put_Delta() {
  return Normal_CDF(d_plus()) - 1;
}

double Option::Put_Gamma() {
  return Call_Gamma();
}

double Option::Put_Vega() {
  return Call_Vega(); 
}

double Option::Put_Theta() {
  return -(S * Normal_PDF(d_plus()) * v) / (2 * sqrt(T)) 
    + r * K * exp(- r * T) * Normal_CDF(- d_minus());
}

double Option::Put_Rho() {
  return - T * K * exp(- r * T) * Normal_CDF(- d_minus());
}
