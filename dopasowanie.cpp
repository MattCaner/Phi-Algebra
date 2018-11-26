#include"dopasowanie.hpp"

double PhiExpression::count(int A, int B, int C, int D, double phi){
    return ( (double)A + (double)B * phi ) / ((double)C + (double)D * phi);
}

PhiExpression::PhiExpression(double x, int precision, double phi): A_(1), B_(1), C_(1), D_(1), phi_(phi){
    adjustTo(x,precision);
}

void PhiExpression::adjustTo(double x, int precision){
    //LINEAR METHOD
        double chi = (1+phi_)/2;
        for(int k = 1; k<100; k++){
            double targetAB = chi*k*x;
            double targetCD = chi*k;
            #ifdef LOUD
            std::cout << "k = " << k << std::endl; 
            #endif //LOUD

            while(Jump(targetAB,&A_,&B_,phi_));
            while(Jump(targetCD,&C_,&D_,phi_));
        }
}

ostream& operator<<(ostream& os, const PhiExpression& pe){
    os << "(" << pe.A_ << "+" << pe.B_ << "phi)/(" << pe.C_ << "+" << pe.D_ << "phi)";
}