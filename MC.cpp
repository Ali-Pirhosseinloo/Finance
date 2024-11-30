#include <random>
#include <vector>
#include "MC.h"

std::vector<double> normal_random(int num_samples,
                                  double mean, 
                                  double stddev, 
                                  unsigned seed) {
                                    
    std::default_random_engine generator(seed);

    std::normal_distribution<double> distribution(mean, stddev);

    // Generate random numbers
    std::vector<double> samples;
    samples.reserve(num_samples);
    for (int i = 0; i < num_samples; ++i) {
        samples.push_back(distribution(generator));
    }

    return samples;
}