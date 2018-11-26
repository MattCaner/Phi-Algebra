#include"dopasowanie.hpp"

int main(){
    double num = 17.81;
    PhiExpression p1(num,10,M_PHI);
    std::cout<< p1 << " wartosc faktyczna: " << p1.getAsNumber() << " wartosc docelowa: " << num << "  roznica:" << abs(p1.getAsNumber()-num) << std::endl;
    return 0;
}