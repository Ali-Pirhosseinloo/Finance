#include <cmath>
#include <algorithm>
#include "AmericanOption.h"

double AmericanOption::Call_PayOff(const double& X) const {
        return std::max(X - K, 0.0);
    }

double AmericanOption::Put_PayOff(const double& X) const {
        return std::max(K - X, 0.0);
}