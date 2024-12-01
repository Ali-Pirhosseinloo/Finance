#ifndef NormRand_Gen_H
#define NormRand_Gen_H
#include <random>

extern std::default_random_engine generator;
extern std::normal_distribution<double> distribution;

double Normal_Rand();

double Normal_CDF(const double x);

double Normal_PDF(const double x);

#endif