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


std::vector<double> AsianOption::path_price_generator(const std::vector<double>& initial_prices) const {

        std::vector<double> spot_prices = initial_prices;
        double dt = T / static_cast<double>(spot_prices.size());

        for (size_t i = 1; i < spot_prices.size(); ++i) {
            spot_prices[i] = spot_prices[i - 1] * exp(dt * (r - 0.5 * v * v) + std::sqrt(v * v * dt) * Normal_Rand());
        }

        return spot_prices;
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


double AsianOption::Asian_MC_Call_Price() const{
    unsigned num_sims = 100;
    unsigned num_intervals = 25;
    std::vector<double> spot_prices(num_intervals, S);
    double payoff_sum = 0.0;
  for (int i=0; i<num_sims; i++) {
    payoff_sum += Asian_Call_PayOff(path_price_generator(spot_prices));
  }
  return ((payoff_sum / static_cast<double>(num_sims)) * exp(-r*T));

}


double AsianOption::Asian_MC_Put_Price() const {
    unsigned num_sims = 100;
    unsigned num_intervals = 25;
    std::vector<double> spot_prices(num_intervals, S);
    double payoff_sum = 0.0;
  for (int i=0; i<num_sims; i++) {
    payoff_sum += Asian_Put_PayOff(path_price_generator(spot_prices));
  }
  return (payoff_sum / static_cast<double>(num_sims)) * exp(-r*T);

}