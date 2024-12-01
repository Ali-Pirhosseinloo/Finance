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

        double MC_Call_Price(int num_simulations = 100000) const;

        double MC_Put_Price(int num_simulations = 100000) const;

        double BSM_Call_Price();

        double BSM_Put_Price();

        double Call_Delta();

        double Call_Gamma();

        double Call_Vega();

        double Call_Theta();

        double Call_Rho();

        double Put_Delta();

        double Put_Gamma();

        double Put_Vega();

        double Put_Theta();

        double Put_Rho();

        virtual ~Option() {}
        
};

#endif