#pragma once
#include"util.hpp"

/*
    Usage:
    Create PhiExpression with one of constructors or with explicit converter.
    You can add, subtract, multiply and divide PhiExpressions with normal operators.
    You can write PhiExpression with ostream or implement your own printing function.

*/

class PhiExpression{
public:
    //constructors:
    PhiExpression(int A = 0, int B = 0, int C = 0, int D = 0, double phi = M_PHI):  //default constructor initialises all values in fields.
        A_(A), B_(B), C_(C), D_(D), phi_(phi){ }
    PhiExpression(double x, int precision, double phi = M_PHI);     //creates a phi expression that is closer to x than [precision]
    //basic utility functions:
    void adjustTo(double x, int precision);          //adjusts expression to x with given precision
    double getAsNumber() const {return count(A_,B_,C_,D_,phi_);}    //returns numerical value of expression as single double
    PhiExpression simplify();                                                //simplifies the expression, dividing both numerator and numerator by largest possible integer
    PhiExpression compress();                                //forcefully simplifies with some compression. The higher the number, the more inefficient compression will be
    operator double() const {return getAsNumber();}                 //implicit conversion to double
    //operators:
    PhiExpression operator+(const PhiExpression& pe);   //arithmetic operators
    PhiExpression operator*(const PhiExpression& pe);
    PhiExpression operator*(double d);   
    PhiExpression operator-(const PhiExpression& pe);
    PhiExpression operator/(const PhiExpression& pe);
    //get-only functions for internal variables
    int getA() const {return A_;}   //get functions for A, B, C, D value
    int getB() const {return B_;}
    int getC() const {return C_;}
    int getD() const {return D_;}
    //static functions:
    static double count(int A, int B, int C, int D, double phi = M_PHI);        //returns numerical value of any phi expression of given attributes
    //befriended functions:
    friend ostream& operator<<(ostream& os, const PhiExpression& pe);           //befriended ostream enables using cout to write to console
private:
    //private variables:
    int A_;     //basic attributes of phi expression
    int B_;
    int C_;
    int D_;
    //generally those are constants that should not be modified:
    double phi_;        //value of phi
    const int hardLimit = 10000;    //hard limit of iterations in adjustment algorithm.
    //private methods:
    static bool Jump(double target, int* P, int* R,double phi_);   //performs a jump
};