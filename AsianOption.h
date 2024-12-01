#ifndef AsianOption_H
#define AsianOption_H
#include "Option.h"
#include <vector>

class AsianOption : public Option {

public:

    using Option::Option;

    double Call_PayOff(const double& X) const override;

    double Put_PayOff(const double& X) const override;

    std::vector<double> path_price_generator(const std::vector<double>& initial_prices) const;

    double Asian_Call_PayOff(const std::vector<double>& spot_prices) const;

    double Asian_Put_PayOff(const std::vector<double>& spot_prices) const;

    double Asian_MC_Call_Price() const;

    double Asian_MC_Put_Price() const;

    virtual ~AsianOption() {};
};

#endif