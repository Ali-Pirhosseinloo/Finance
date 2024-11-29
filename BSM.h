#ifndef BSM_H
#define BSM_H
#include "Option.h"

double normal_cdf(double x, double mean = 0.0, double stddev = 1.0);

class BSM : public Option {

    public:

        double d_plus();

        double d_minus();

        double call_BSM_price();

        double put_BSM_price();

};

#endif