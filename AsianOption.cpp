#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include "AsianOption.h"


double AsianOption::Call_PayOff(const double& X) const {
        return std::max(X - K, 0.0);
    }

double AsianOption::Put_PayOff(const double& X) const {
        return std::max(K - X, 0.0);
}


void AsianOption::path_price_generator(std::vector<double> spot_prices) {

    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0, 1.0);

    double Z = distribution(generator);
    double dt = T/static_cast<double>(spot_prices.size());

    for (int i=1; i<spot_prices.size(); i++) {
    spot_prices[i] = spot_prices[i-1] * exp( dt * (r - 0.5 * v * v) + std::sqrt(v * v * dt) * Z);
    } 
}


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


double AsianOption::Asian_MC_Call_Price() {
    unsigned num_sims = 100000;
    unsigned num_intervals = 250;
    std::vector<double> spot_prices(num_intervals, S);
    double payoff_sum = 0.0;
  for (int i=0; i<num_sims; i++) {
    path_price_generator(spot_prices);
    payoff_sum += Asian_Call_PayOff(spot_prices);
  }
  return ((payoff_sum / static_cast<double>(num_sims)) * exp(-r*T));

}


double AsianOption::Asian_MC_Put_Price() {
    unsigned num_sims = 100000;
    unsigned num_intervals = 250;
    std::vector<double> spot_prices(num_intervals, S);
    double payoff_sum = 0.0;
  for (int i=0; i<num_sims; i++) {
    path_price_generator(spot_prices);
    payoff_sum += Asian_Put_PayOff(spot_prices);
  }
  return (payoff_sum / static_cast<double>(num_sims)) * exp(-r*T);

}