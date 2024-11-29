#include "BSM.h"
#include <iostream>
#include <cmath>

double normal_cdf(double x, double mean, double stddev) {
    return 0.5 * (1.0 + std::erf((x - mean) / (stddev * std::sqrt(2.0))));
}

double BSM::d_plus() {
return (log(S/K) + (r + 0.5*v*v)*T)/(v*(pow(T,0.5)));
}

double BSM::d_minus() {
return (log(S/K) + (r - 0.5*v*v)*T)/(v*(pow(T,0.5)));
}

double BSM::call_BSM_price() {
return S * normal_cdf(d_plus())-K*exp(-r*T) * normal_cdf(d_minus());
}

double BSM::put_BSM_price() {
return -S*normal_cdf(-d_plus())+K*exp(-r*T) * normal_cdf(-d_minus());
}