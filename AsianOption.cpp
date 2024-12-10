#include <vector>
#include <cmath>
#include <algorithm>
#include "AsianOption.h"
#include "NormRand_Gen.h"


double AsianOption::Call_PayOff(const double& X) const {
        return std::max(X - K, 0.0);
    }

double AsianOption::Put_PayOff(const double& X) const {
        return std::max(K - X, 0.0);
}


  std::vector<double> AsianOption::path_price_generator(const std::vector<double>& initial_prices, double r1,  double v1,  double T1) const {

        std::vector<double> spot_prices = initial_prices;
        double dt = T1 / static_cast<double>(spot_prices.size());

        for (size_t i = 1; i < spot_prices.size(); ++i) {
            spot_prices[i] = spot_prices[i - 1] * exp(dt * (r1 - 0.5 * v1 * v1) + std::sqrt(v1 * v1 * dt) * Normal_Rand());
        }

        return spot_prices;
    }


  std::vector<double> AsianOption::path_price_generator(const std::vector<double>& initial_prices) const {
  return path_price_generator(initial_prices, r, v, T);
  }


  //------------------------------------------------------------------------


double AsianOption::Asian_Call_PayOff(const std::vector<double>& spot_prices) const {
  unsigned num_times = spot_prices.size();
  double sum = std::accumulate(spot_prices.begin(), spot_prices.end(), 0);
  double mean = sum / static_cast<double>(num_times);
  return Call_PayOff(mean);
}

double AsianOption::Asian_Put_PayOff(const std::vector<double>& spot_prices) const {
  unsigned num_times = spot_prices.size();
  double sum = std::accumulate(spot_prices.begin(), spot_prices.end(), 0);
  double mean = sum / static_cast<double>(num_times);
  return Put_PayOff(mean);
}


//------------------------------------------------------------------------



double AsianOption::Asian_MC_Call_Price(double S1, double K1, double r1,  double v1,  double T1) const {
    unsigned num_sims = 100000;
    unsigned num_intervals = 25;
    std::vector<double> spot_prices(num_intervals, S1);
    double payoff_sum = 0.0;
  for (int i=0; i<num_sims; i++) {
    payoff_sum += Asian_Call_PayOff(path_price_generator(spot_prices));
  }
  return ((payoff_sum / static_cast<double>(num_sims)) * exp(-r1*T1));

}

double AsianOption::Asian_MC_Put_Price(double S1, double K1, double r1,  double v1,  double T1) const {
    unsigned num_sims = 100000;
    unsigned num_intervals = 25;
    std::vector<double> spot_prices(num_intervals, S1);
    double payoff_sum = 0.0;
  for (int i=0; i<num_sims; i++) {
    payoff_sum += Asian_Put_PayOff(path_price_generator(spot_prices));
  }
  return (payoff_sum / static_cast<double>(num_sims)) * exp(-r1*T1);

}

double AsianOption::Asian_MC_Call_Price() const{
  return Asian_MC_Call_Price(S, K, r, v, T);
}


double AsianOption::Asian_MC_Put_Price() const {
  return Asian_MC_Put_Price(S, K, r, v, T);
}

//------------------------------------------------------------------------

double AsianOption::Asian_Call_Delta_FDM(double delta_S) {
  return (Asian_MC_Call_Price(S + delta_S, K, r, v, T) - Asian_MC_Call_Price(S - delta_S, K, r, v, T)) / (2 * delta_S);
}

double AsianOption::Asian_Call_Gamma_FDM(double delta_S) {
  return (Asian_MC_Call_Price(S + delta_S, K, r, v, T) - 2 * Asian_MC_Call_Price() + Asian_MC_Call_Price(S - delta_S, K, r, v, T)) / (delta_S * delta_S);
}

double AsianOption::Asian_Call_Vega_FDM(double delta_v) {
  return (Asian_MC_Call_Price(S, K, r, v + delta_v, T) - Asian_MC_Call_Price(S, K, r, v - delta_v, T)) / (2 * delta_v);
}

double AsianOption::Asian_Call_Theta_FDM(double delta_T) {
  return -(Asian_MC_Call_Price(S, K, r, v, T + delta_T) - Asian_MC_Call_Price(S, K, r, v , T - delta_T)) / (2 * delta_T);
}

double AsianOption::Asian_Call_Rho_FDM(double delta_r) {
  return (Asian_MC_Call_Price(S, K, r + delta_r, v, T) - Asian_MC_Call_Price(S, K, r - delta_r, v , T)) / (2 * delta_r);
}

//------------------------------------------------------------------------

double AsianOption::Asian_Put_Delta_FDM(double delta_S) {
  return (Asian_MC_Put_Price(S + delta_S, K, r, v, T) - Asian_MC_Put_Price(S - delta_S, K, r, v, T)) / (2 * delta_S);
}

double AsianOption::Asian_Put_Gamma_FDM(double delta_S) {
  return (Asian_MC_Put_Price(S + delta_S, K, r, v, T) - 2 * Asian_MC_Put_Price() + Asian_MC_Put_Price(S - delta_S, K, r, v, T)) / (delta_S * delta_S);
}

double AsianOption::Asian_Put_Vega_FDM(double delta_v) {
  return (Asian_MC_Put_Price(S, K, r, v + delta_v, T) - Asian_MC_Put_Price(S, K, r, v - delta_v, T)) / (2 * delta_v);
}

double AsianOption::Asian_Put_Theta_FDM(double delta_T) {
  return -(Asian_MC_Put_Price(S, K, r, v, T + delta_T) - Asian_MC_Put_Price(S, K, r, v , T - delta_T)) / (2 * delta_T);
}

double AsianOption::Asian_Put_Rho_FDM(double delta_r) {
  return (Asian_MC_Put_Price(S, K, r + delta_r, v, T) - Asian_MC_Put_Price(S, K, r - delta_r, v , T)) / (2 * delta_r);
}