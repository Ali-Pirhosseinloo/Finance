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

    // Monte Carlo Simulation for Call Option
    double Option::MC_Call_Price(double S1, double K1, double r1,  double v1,  double T1, int num_simulations) const {

        double sum_payoffs = 0.0;

        for (int i = 0; i < num_simulations; ++i) {

            double simulated_price = S1 * std::exp(T1 * (r1 - 0.5 * v1 * v1) + v1 * std::sqrt(T1) * Normal_Rand());

            sum_payoffs += Call_PayOff(simulated_price);
        }

        return (std::exp(- r1 * T1) * sum_payoffs) / num_simulations;
    }

    // Monte Carlo Simulation for Put Option
    double Option::MC_Put_Price(double S1, double K1, double r1,  double v1,  double T1, int num_simulations) const {

        double sum_payoffs = 0.0;

        for (int i = 0; i < num_simulations; ++i) {

            double simulated_price = S1 * std::exp(T1 * (r1 - 0.5 * v1 * v1) + v1 * std::sqrt(T1) * Normal_Rand());

            sum_payoffs += Put_PayOff(simulated_price);
        }

        return (std::exp(- r1 * T1) * sum_payoffs) / num_simulations;
    }


    double Option::MC_Call_Price(int num_simulations) const {
      return MC_Call_Price(S, K, r, v, T, num_simulations);
    }

    double Option::MC_Put_Price(int num_simulations) const {
        return MC_Put_Price(S, K, r, v, T, num_simulations);
    }


//------------------------------------------------------------------------

double Option::d_plus() { // Black-Scholes-Merton d_plus
return (log(S/K) + (r + 0.5 * v * v) * T) / (v * (pow(T,0.5)));
}

double Option::d_minus() { // Black-Scholes-Merton d_minus
return (log(S/K) + (r - 0.5 * v * v) * T) / (v * (pow(T,0.5)));
}

//------------------------------------------------------------------------

double Option::BSM_Call_Price() { // Black-Scholes-Merton Call Price
return S * Normal_CDF(d_plus())-K * exp(- r * T) * Normal_CDF(d_minus());
}

double Option::BSM_Put_Price() { // Black-Scholes-Merton Put Price
return -S * Normal_CDF(-d_plus()) + K * exp(- r * T) * Normal_CDF(-d_minus());
}

//------------------------------------------------------------------------

double Option::Call_Delta_BSM() { // Black-Scholes-Merton Call Delta
  return Normal_CDF(d_plus());
}

double Option::Call_Gamma_BSM() { // Black-Scholes-Merton Call Gamma
  return Normal_PDF(d_plus())/(S * v * sqrt(T));
}

double Option::Call_Vega_BSM() { // Black-Scholes-Merton Call Vega
  return S * Normal_PDF(d_plus()) * sqrt(T);
}

double Option::Call_Theta_BSM() { // Black-Scholes-Merton Call Theta
  return -(S * Normal_PDF(d_plus()) * v)/(2 * sqrt(T)) 
    - r * K * exp(-r * T) * Normal_CDF(d_minus());
}

double Option::Call_Rho_BSM() { // Black-Scholes-Merton Call Rho
  return K * T * exp(-r * T) * Normal_CDF(d_minus());
}

//------------------------------------------------------------------------/

double Option::Put_Delta_BSM() { // Black-Scholes-Merton Put Delta
  return Normal_CDF(d_plus()) - 1;
}

double Option::Put_Gamma_BSM() { // Black-Scholes-Merton Put Gamma
  return Call_Gamma_BSM();
}

double Option::Put_Vega_BSM() { // Black-Scholes-Merton Put Vega
  return Call_Vega_BSM(); 
}

double Option::Put_Theta_BSM() { // Black-Scholes-Merton Put Theta
  return -(S * Normal_PDF(d_plus()) * v) / (2 * sqrt(T)) 
    + r * K * exp(- r * T) * Normal_CDF(- d_minus());
}

double Option::Put_Rho_BSM() { // Black-Scholes-Merton Put Rho
  return - T * K * exp(- r * T) * Normal_CDF(- d_minus());
}

//------------------------------------------------------------------------

double Option::Call_Delta_FDM(double delta_S) { // Finite Difference Method for Call Delta
  return (MC_Call_Price(S + delta_S, K, r, v, T) - MC_Call_Price(S - delta_S, K, r, v, T)) / (2 * delta_S);
}

double Option::Call_Gamma_FDM(double delta_S) { // Finite Difference Method for Call Gamma
  return (MC_Call_Price(S + delta_S, K, r, v, T) - 2 * MC_Call_Price() + MC_Call_Price(S - delta_S, K, r, v, T)) / (delta_S * delta_S);
}

double Option::Call_Vega_FDM(double delta_v) { // Finite Difference Method for Call Vega
  return (MC_Call_Price(S, K, r, v + delta_v, T) - MC_Call_Price(S, K, r, v - delta_v, T)) / (2 * delta_v);
}

double Option::Call_Theta_FDM(double delta_T) { // Finite Difference Method for Call Theta
  return -(MC_Call_Price(S, K, r, v, T + delta_T) - MC_Call_Price(S, K, r, v , T - delta_T)) / (2 * delta_T);
}

double Option::Call_Rho_FDM(double delta_r) { // Finite Difference Method for Call Rho
  return (MC_Call_Price(S, K, r + delta_r, v, T) - MC_Call_Price(S, K, r - delta_r, v , T)) / (2 * delta_r);
}

//------------------------------------------------------------------------

double Option::Put_Delta_FDM(double delta_S) { // Finite Difference Method for Put Delta
  return (MC_Put_Price(S + delta_S, K, r, v, T) - MC_Put_Price(S - delta_S, K, r, v, T)) / (2 * delta_S);
}

double Option::Put_Gamma_FDM(double delta_S) { // Finite Difference Method for Put Gamma
  return (MC_Put_Price(S + delta_S, K, r, v, T) - 2 * MC_Put_Price() + MC_Put_Price(S - delta_S, K, r, v, T)) / (delta_S * delta_S);
}

double Option::Put_Vega_FDM(double delta_v) { // Finite Difference Method for Put Vega
  return (MC_Put_Price(S, K, r, v + delta_v, T) - MC_Put_Price(S, K, r, v - delta_v, T)) / (2 * delta_v);
}

double Option::Put_Theta_FDM(double delta_T) { // Finite Difference Method for Put Theta
  return -(MC_Put_Price(S, K, r, v, T + delta_T) - MC_Put_Price(S, K, r, v , T - delta_T)) / (2 * delta_T);
}

double Option::Put_Rho_FDM(double delta_r) { // Finite Difference Method for Put Rho
  return (MC_Put_Price(S, K, r + delta_r, v, T) - MC_Put_Price(S, K, r - delta_r, v , T)) / (2 * delta_r);
}
