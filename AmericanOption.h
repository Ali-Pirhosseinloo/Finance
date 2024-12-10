#ifndef AmericanOption_H
#define AmericanOption_H
#include "Option.h"

class AmericanOption : public Option {
public:
    using Option::Option;

    double Call_PayOff(const double& X) const override;

    double Put_PayOff(const double& X) const override;
    
    double BNT_Put_Price(double S1, double K1, double r1, double v1, double T1, int N = 1000);

    double BNT_Put_Price(int N = 1000);

    double American_Put_Delta_FDM(double delta_S = 1);

    double American_Put_Gamma_FDM(double delta_S = 1);

    double American_Put_Vega_FDM(double delta_v = 0.1);

    double American_Put_Theta_FDM(double delta_T = 0.1);

    double American_Put_Rho_FDM(double delta_r = 0.01);

    virtual ~AmericanOption() {};
};

#endif