#include <random>
#include <vector>

std::vector<double> normal_random(int num_samples,
                                  double mean, 
                                  double stddev, 
                                  unsigned seed) {
                                    
    // Create a random engine with an optional seed
    std::default_random_engine generator(seed);

    // Define the normal distribution
    std::normal_distribution<double> distribution(mean, stddev);

    // Generate random numbers
    std::vector<double> samples;
    samples.reserve(num_samples);
    for (int i = 0; i < num_samples; ++i) {
        samples.push_back(distribution(generator));
    }

    return samples;
}
