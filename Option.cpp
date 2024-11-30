#include <cmath>
#include <random>
#include <algorithm>
#include "Option.h"


Option::Option (const double& _S, const double& _K,const double& _r, const double& _v, const double& _T): 
        S(_S), 
        K(_K),
        r(_r),
        v(_v),
        T(_T)
        {}


    double Option::MC_Call_Price(int num_simulations) const {

        std::default_random_engine generator;
        std::normal_distribution<double> distribution(0.0, 1.0);

        double sum_payoffs = 0.0;

        for (int i = 0; i < num_simulations; ++i) {

            double Z = distribution(generator);

            double simulated_price = S * std::exp(T * (r - 0.5 * v * v) + v * std::sqrt(T) * Z);

            sum_payoffs += Call_PayOff(simulated_price);
        }

        return (std::exp(- r * T) * sum_payoffs) / num_simulations;
    }



        double Option::MC_Put_Price(int num_simulations) const {

        std::default_random_engine generator;
        std::normal_distribution<double> distribution(0.0, 1.0);

        double sum_payoffs = 0.0;

        for (int i = 0; i < num_simulations; ++i) {

            double Z = distribution(generator);

            double simulated_price = S * std::exp(T * (r - 0.5 * v * v) + v * std::sqrt(T) * Z);

            sum_payoffs += Put_PayOff(simulated_price);
        }

        return (std::exp(- r * T) * sum_payoffs) / num_simulations;
    }

