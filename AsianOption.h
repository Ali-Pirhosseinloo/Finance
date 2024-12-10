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

    std::vector<double> path_price_generator(const std::vector<double>& initial_prices, double r1,  double v1,  double T1) const;

    double Asian_Call_PayOff(const std::vector<double>& spot_prices) const;

    double Asian_Put_PayOff(const std::vector<double>& spot_prices) const;

    double Asian_MC_Call_Price() const;

    double Asian_MC_Put_Price() const;

    double Asian_MC_Call_Price(double S1, double K1, double r1,  double v1,  double T1) const;

    double Asian_MC_Put_Price(double S1, double K1, double r1,  double v1,  double T1) const;

    double Asian_Call_Delta_FDM(double delta_S = 1);

    double Asian_Call_Gamma_FDM(double delta_S = 1);

    double Asian_Call_Vega_FDM(double  delta_v = 0.1);

    double Asian_Call_Theta_FDM(double delta_T = 0.1);

    double Asian_Call_Rho_FDM(double delta_r = 0.01);

    double Asian_Put_Delta_FDM(double delta_S = 1);

    double Asian_Put_Gamma_FDM(double delta_S = 1);

    double Asian_Put_Vega_FDM(double delta_v = 0.1);

    double Asian_Put_Theta_FDM(double delta_T = 0.1);

    double Asian_Put_Rho_FDM(double delta_r = 0.01);

    virtual ~AsianOption() {};
};

#endif