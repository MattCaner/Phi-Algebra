#include"dopasowanie.hpp"
#include<limits.h>

double PhiExpression::count(int A, int B, int C, int D, double phi){
    return ( (double)A + (double)B * phi ) / ((double)C + (double)D * phi);
}

PhiExpression::PhiExpression(double x, int precision, double phi): A_(1), B_(1), C_(1), D_(1), phi_(phi){
    adjustTo(x,precision);
}

void PhiExpression::adjustTo(double x, int precision){
    //LINEAR METHOD
        double chi = (1+phi_)/2;
        double targetAB = chi;
        double targetCD = chi;
        for(int k = 1; k<hardLimit; k++){
            //tutaj jest klucz do dzialania programu

            targetCD = k*getAsNumber();
            while(Jump(targetCD,&C_,&D_,phi_));

            targetAB = (C_+D_*phi_)*x;
            while(Jump(targetAB,&A_,&B_,phi_));
            cout << targetAB << " " << targetCD << " " << k << endl;
        }
    simplify();
}

PhiExpression PhiExpression::operator+(const PhiExpression& pe){
    return PhiExpression(A_*pe.C_+pe.A_*C_+B_*pe.D_+pe.B_*D_, A_*pe.D_+B_*pe.C_+D_*pe.A_+C_*pe.B_+B_*pe.D_+D_*pe.B_,C_*pe.C_+D_*pe.D_,C_*pe.D_+D_*pe.C_+D_*pe.D_).simplify();
}

PhiExpression PhiExpression::operator*(double d){
    return PhiExpression(A_*d,B_*d,C_,D_).simplify();
}
PhiExpression PhiExpression::operator*(const PhiExpression& pe){
    return PhiExpression(A_*pe.A_+B_*pe.B_,B_*pe.A_+A_*pe.B_+B_*pe.B_,C_*pe.C_+D_*pe.D_,C_*pe.D_+D_*pe.C_+D_*pe.D_).simplify();
}
PhiExpression PhiExpression::operator-(const PhiExpression& pe){
    return *this+PhiExpression(-pe.A_,-pe.B_,pe.C_,pe.C_).simplify();
}
PhiExpression PhiExpression::operator/(const PhiExpression& pe){
    //to be added
    if(pe.A_==0&&pe.B_==0){
        std::cout<<"!!!WARNING!!!" << std::endl<< "DIVISION BY ZERO. EMPTY EXPRESSION WILL BE GENERATED" << std::endl;
        return PhiExpression(0,0,INT_MAX,INT_MAX);
    }
    else{
        return ((*this)*PhiExpression(pe.C_,pe.D_,pe.A_,pe.B_)).simplify();
    }
}

ostream& operator<<(ostream& os, const PhiExpression& pe){
    return os << "(" << pe.A_ << "+" << pe.B_ << "phi)/(" << pe.C_ << "+" << pe.D_ << "phi)";
}

PhiExpression PhiExpression::simplify(){
    int divisor = GCD4(A_,B_,C_,D_);
    cout << divisor << endl;
    A_ /= divisor;
    B_ /= divisor;
    C_ /= divisor;
    D_ /= divisor;
    return *this;
}

bool PhiExpression::Jump(double target, int* P, int* R,double phi_){
    #ifdef LOUD
    std::cout << *P << " " << *R << std::endl;
    #endif //LOUD
    double diff[5];
    diff[0] = abs(target-(*P+*R*phi_));
    diff[1] = abs(target-(*P+1+*R*phi_));
    diff[2] = abs(target-(*P-1+*R*phi_));
    diff[3] = abs(target-(*P+(*R+1)*phi_));
    diff[4] = abs(target-(*P+(*R-1)*phi_));

    switch(MinIndex(diff,5)){
        case 0:
            return 0;
        break;
        case 1:
            *P += (int)diff[1]>0?(int)diff[1]:1;
        break;
        case 2:
            *P -= (int)diff[2]>0?(int)diff[2]:1;
        break;
        case 3:
            *R += (int)diff[3]>0?(int)diff[3]:1;
        break;
        case 4:
            *R -= (int)diff[4]>0?(int)diff[4]:1;
        break;
    }
    return 1;
}