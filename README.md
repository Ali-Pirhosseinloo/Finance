# Option Pricing and Greeks Calculation in C++  

This project implements financial derivatives pricing and risk analysis in C++. It includes functionality for European, Asian, and American options using industry-standard methods like Black-Scholes-Merton (BSM), Monte Carlo simulations, and binomial trees. Additionally, it calculates the Greeks to measure sensitivity to various parameters.  

## Features  
- **European Options**:  
  - Pricing using Black-Scholes-Merton and Monte Carlo methods.  
  - Payoff calculation for call and put options.  
  - Greeks calculation using BSM and finite difference approximations.  

- **Asian Options**:  
  - Monte Carlo pricing for Asian options.  
  - Path price generation to simulate spot price trajectories.  
  - Greeks calculation using finite difference methods.  

- **American Options**:  
  - Pricing using binomial tree models.  
  - Payoff calculation for American-style options.  
  - Greeks calculation via finite difference methods.
    

## File Descriptions  

### `NormRand_Gen.cpp`  
Generates normally distributed random numbers and includes functions to calculate the PDF and CDF of the normal distribution.  

### `EuropeanOption.cpp`  
Calculates the payoff for European call and put options and implements pricing using Black-Scholes-Merton and Monte Carlo methods.  

### `AsianOption.cpp`  
Handles specialized calculations for Asian options:  
- Generates simulated paths of spot prices.  
- Prices Asian options using Monte Carlo simulations.  
- Computes Greeks (Delta, Gamma, Theta, Vega, Rho) using finite difference approximations.  

### `AmericanOption.cpp`  
Implements pricing for American options:  
- Calculates payoffs for call and put options.  
- Prices American options using binomial tree models.  
- Computes Greeks using finite difference methods.  

### `main.cpp`  
Defines key market parameters and demonstrates the functionality of the program by:  
- Creating instances of European, Asian, and American options.  
- Calculating and displaying option prices and Greeks for given parameters.  

## How to Run  

1. **Clone the Repository**:

2.
    ```
   git clone https://github.com/Ali-Pirhosseinloo/option-pricing.git
   cd Option-Pricing
   ```

3. **Compile the Code**:



## Input Parameters  
The program uses the following predefined market parameters:  
- **Spot Price (\(S\))**: 100.0  
- **Strike Price (\(K\))**: 100.0  
- **Risk-Free Rate (\(r\))**: 0.05  
- **Volatility (\(v\))**: 0.2  
- **Time to Maturity (\(T\))**: 1.0  

These values are set in `main.cpp`, but you can modify them to test different scenarios and simulate various market conditions.  

## Output Format  
The program will print the following results based on the predefined market parameters:  
- **European Call/Put Prices**:  
   - European Call/Put price using Black-Scholes-Merton (BSM).  
   - European Call/Put price using Monte Carlo (MC).  
- **Asian Call Prices**:  
   - Asian Call price using Monte Carlo (MC).  
- **American Put Prices**:  
   - American Put price using Binomial Trees.  
- **Greeks**:  
   - European option Greeks (Delta, Gamma, Theta, Vega, Rho) using both Black-Scholes-Merton (BSM) and finite difference methods.  
   - American Put option Greeks (Delta, Gamma, Theta, Vega, Rho) using finite difference methods.  
   - Asian Call/Put option Greeks (Delta, Gamma, Theta, Vega, Rho) using finite difference methods.  
