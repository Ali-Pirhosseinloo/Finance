#ifndef Option_H
#define Option_H

class Option {

    protected:

        double    S        // asset_spot_price
                , K        // strike price
                , r        // interest rate
                , v        // volatility
                , T;       // time to maturity

        double d_plus();
        double d_minus();       

    public:

        Option (const double& _S, const double& _K,const double& _r, const double& _v, const double& _T);

        virtual double Call_PayOff(const double& X) const = 0;

        virtual double Put_PayOff(const double& X) const = 0;

        double MC_Call_Price(double S1, double K1, double r1,  double v1,  double T1 , int num_simulations = 1000000) const;

        double MC_Put_Price(double S1, double K1, double r1,  double v1,  double T1, int num_simulations = 1000000) const;

        double MC_Call_Price(int num_simulations = 1000000) const;

        double MC_Put_Price(int num_simulations = 1000000) const;

        double BSM_Call_Price();

        double BSM_Put_Price();

        double Call_Delta_BSM();

        double Call_Gamma_BSM();

        double Call_Vega_BSM();

        double Call_Theta_BSM();

        double Call_Rho_BSM();

        double Put_Delta_BSM();

        double Put_Gamma_BSM();

        double Put_Vega_BSM();

        double Put_Theta_BSM();

        double Put_Rho_BSM();

        double Call_Delta_FDM(double delta_S = 1);

        double Call_Gamma_FDM(double delta_S = 1);

        double Call_Vega_FDM(double  delta_v = 0.1);

        double Call_Theta_FDM(double delta_T = 0.1);

        double Call_Rho_FDM(double delta_r = 0.01);

        double Put_Delta_FDM(double delta_S = 1);

        double Put_Gamma_FDM(double delta_S = 1);

        double Put_Vega_FDM(double delta_v = 0.1);

        double Put_Theta_FDM(double delta_T = 0.1);

        double Put_Rho_FDM(double delta_r = 0.01);

        virtual ~Option() {}
        
};

#endif