#ifndef Option_H
#define Option_H

class Option {

    protected:

        double    S        // asset_spot_price
                , K        // strike price
                , r        // interest rate
                , v        // volatility
                , T;       // time to maturity

    public:

        Option (const double& S, const double& K,const double& r, const double& v, const double& T);
        
};

#endif