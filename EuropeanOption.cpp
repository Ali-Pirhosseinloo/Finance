#include <cmath>
#include <algorithm>
#include "EuropeanOption.h"

double EuropeanOption::Call_PayOff(const double& X) const {
        return std::max(X - K, 0.0);
    }

double EuropeanOption::Put_PayOff(const double& X) const {
        return std::max(K - X, 0.0);
}