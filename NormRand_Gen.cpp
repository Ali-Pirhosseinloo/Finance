#include "NormRand_Gen.h"
#include <random>

std::default_random_engine generator(std::chrono::high_resolution_clock::now().time_since_epoch().count());
std::normal_distribution<double> distribution(0.0, 1.0);

double Normal_Rand() {
        return distribution(generator);
}

double Normal_CDF(const double x) {
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}

double Normal_PDF(const double x) {
  return (1.0/(pow(2 * M_PI,0.5))) * exp(-0.5 * x * x);
}