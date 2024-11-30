#ifndef AsianOption_H
#define AsianOption_H
#include "Option.h"
#include <vector>

class AsianOption : public Option {

public:

    using Option::Option;

    double Call_PayOff(const double& X) const override;

    double Put_PayOff(const double& X) const override;

    void path_price_generator(std::vector<double> spot_prices);

    double Asian_Call_PayOff(const std::vector<double>& spot_prices) const;

    double Asian_Put_PayOff(const std::vector<double>& spot_prices) const;

    double Asian_MC_Call_Price();

    double Asian_MC_Put_Price();

    virtual ~AsianOption() {};
};

#endif