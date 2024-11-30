#ifndef EuropeanOption_H
#define EuropeanOption_H
#include "Option.h"

class EuropeanOption : public Option {
public:
    using Option::Option;

    double Call_PayOff(const double& X) const override;

    double Put_PayOff(const double& X) const override;

    virtual ~EuropeanOption() {};
};

#endif