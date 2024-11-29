#ifndef MC_H
#define MC_H
#include <vector>
#include <random>

std::vector<double> normal_random(int num_samples,
                                  double mean, 
                                  double stddev, 
                                  unsigned seed = std::random_device{}());


class MC {
    private:

        int n;
        double S,
               K,
               r,
               v,
               T;

    public: 
        MC (const int& n,
            const double& S,
            const double& K, 
            const double& r, 
            const double& v, 
            const double& T);

        double MC_call_price ();

        double MC_put_price ();
};                                 

#endif