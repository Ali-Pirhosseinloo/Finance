#ifndef AmericanOption_H
#define AmericanOption_H
#include "Option.h"

class AmericanOption : public Option {
public:
    using Option::Option;

    double Call_PayOff(const double& X) const override;

    double Put_PayOff(const double& X) const override;

    virtual ~AmericanOption() {};
};

#endif