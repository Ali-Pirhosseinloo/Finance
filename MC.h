#ifndef MC_H
#define MC_H
#include <vector>
#include <random>
#include "Option.h"

std::vector<double> normal_random(int num_samples,
                                  double mean, 
                                  double stddev, 
                                  unsigned seed = std::random_device{}());


class MC : public Option {

    public: 

        double MC_call_price (const int& n);

        double MC_put_price (const int& n);

};                                 

#endif