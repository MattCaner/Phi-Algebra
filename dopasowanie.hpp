#pragma once
#include"util.hpp"

class PhiExpression{
public:
    PhiExpression(int A = 0, int B = 0, int C = 0, int D = 0, double phi = M_PHI): A_(A), B_(B), C_(C), D_(D), phi_(phi){ }
    PhiExpression(double x, int precision, double phi = M_PHI);
    void adjustTo(double x, int precision);

    PhiExpression operator+(const PhiExpression& pe);
    PhiExpression operator*(const PhiExpression& pe);
    PhiExpression operator-(const PhiExpression& pe);
    PhiExpression operator/(const PhiExpression& pe);


    int getA() const {return A_;}
    int getB() const {return B_;}
    int getC() const {return C_;}
    int getD() const {return D_;}
    double getAsNumber() const {return count(A_,B_,C_,D_,phi_);}

    static double count(int A, int B, int C, int D, double phi = M_PHI);

    friend ostream& operator<<(ostream& os, const PhiExpression& pe);


private:
    int A_;
    int B_;
    int C_;
    int D_;
    double phi_;
};