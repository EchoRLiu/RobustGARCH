#pragma
#ifndef ROBGARCH_HEADER_CLASSES_H
#define ROBGARCH_HEADER_CLASSES_H

#include <iostream>
#include <vector>
#include <array>

class RobGarch11
{
public:
  // Constructor: initialize x_, obtain vX_, normX_, vNX_.
  RobGarch11(const std::vector<double>& x);
  
  // Parameters estimations of BM1.
  void optBM1();
  // Parameters estimations of BM2.
  void optBM2();
  
  // Accessors: parameters estimations of BM1 and BM2.
  std::array<double, 3> BM1() const;
  std::array<double, 3> BM2() const;
  
private:
  
  void normalize_();
  double tausq_(const std::vector<double>& x);
  void sEst_(const std::vector<double> x);
  std::vector<double> rho_(const std::vector<double> x);
  // More to come.
  
  
  std::vector<double> x_, normX_;
  double vX_, vNX_, s_;
  int n_;
  double nDouble_;
  double zero_ = 10e-10;
  double tausqConst_ = 0.4797;
  double sEstB_ = 1.625;
  double sEstEmed_ = 0.675;
  
  // More to come.
};



class Division
{
public:

  Division(const std::vector<double> vecN, const double d);
  Division(const std::vector<double> vecN);
  // Vector x is strongly preferred -> required?.
  // Division();
  
  // Access the division result.
  std::vector<double> vecDiv() const;
  double mean() const; // mean of vecNumer_.
  std::vector<double> abs() const; //absolute value of vecDiv();
  std::vector<double> vecNumer() const;
  double denom() const;
  void setVecNumer(const std::vector<double> vecNumer);
  void setDenom(const double denom);
  
  Division operator / (const double rhs) const;
  void operator /= (const double rhs);
  Division operator - (const double rhs) const;
  void operator -= (const double rhs);

private:
  
  std::vector<double> vecNumer_, vecDiv_, vecDivAbs_;
  double denom_;
  double mean_;
  int n_;
  double nDouble_;
  
  void checkForZero_(double d) const;
  void getVecDiv_();
  void getMean_(); // mean of vecNumer_.
  void getAbs_();
  
};


#endif // ROBGARCH_HEADER_CLASSES_H

