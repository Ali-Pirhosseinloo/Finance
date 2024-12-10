#include <cmath>
#include <algorithm>
#include <vector>
#include "AmericanOption.h"

double AmericanOption::Call_PayOff(const double& X) const {
        return std::max(X - K, 0.0);
    }

double AmericanOption::Put_PayOff(const double& X) const {
        return std::max(K - X, 0.0);
}

double AmericanOption::BNT_Put_Price(double S1, double K1, double r1, double v1, double T1, int N) {
    double dt = T1 / N;                // Time step
    double u = exp(v1 * sqrt(dt));  // Up factor
    double d = 1 / u;                  // Down factor
    double p = (exp(r1 * dt) - d) / (u - d); // Risk-neutral probability
    double discount = exp(-r1 * dt);   // Discount factor

    // Create a price tree
    std::vector<std::vector<double>> priceTree(N + 1, std::vector<double>(N + 1, 0.0));
    std::vector<std::vector<double>> optionTree(N + 1, std::vector<double>(N + 1, 0.0));

        // Compute the price tree
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= i; ++j) {
            priceTree[i][j] = S1 * pow(u, j) * pow(d, i - j);
        }
    }

    // Compute option values at maturity
    for (int j = 0; j <= N; ++j) {
        optionTree[N][j] = std::max(K1 - priceTree[N][j], 0.0); // Payoff for a put option
    }

    // Backward induction for option prices
    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            double holdValue = discount * (p * optionTree[i + 1][j + 1] + (1 - p) * optionTree[i + 1][j]);
            double exerciseValue = std::max(K1 - priceTree[i][j], 0.0);
            optionTree[i][j] = std::max(holdValue, exerciseValue); // American option allows early exercise
        }
    }

    return optionTree[0][0]; // Return the option price at the root
}

double AmericanOption::BNT_Put_Price(int N){
        return BNT_Put_Price(S, K, r, v, T, N);
}


double AmericanOption::American_Put_Delta_FDM(double delta_S) {
  return (BNT_Put_Price(S + delta_S, K, r, v, T) - BNT_Put_Price(S - delta_S, K, r, v, T)) / (2 * delta_S);
}

double AmericanOption::American_Put_Gamma_FDM(double delta_S) {
  return (BNT_Put_Price(S + delta_S, K, r, v, T) - 2 * BNT_Put_Price() + BNT_Put_Price(S - delta_S, K, r, v, T)) / (delta_S * delta_S);
}

double AmericanOption::American_Put_Vega_FDM(double delta_v) {
  return (BNT_Put_Price(S, K, r, v + delta_v, T) - BNT_Put_Price(S, K, r, v - delta_v, T)) / (2 * delta_v);
}

double AmericanOption::American_Put_Theta_FDM(double delta_T) {
  return -(BNT_Put_Price(S, K, r, v, T + delta_T) - BNT_Put_Price(S, K, r, v , T - delta_T)) / (2 * delta_T);
}

double AmericanOption::American_Put_Rho_FDM(double delta_r) {
  return (BNT_Put_Price(S, K, r + delta_r, v, T) - BNT_Put_Price(S, K, r - delta_r, v , T)) / (2 * delta_r);
}