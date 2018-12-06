#include"dopasowanie.hpp"

int main(){
    double num = M_PI;
    PhiExpression p1(num,10,M_PHI);
    std::cout<< p1 << " wartosc faktyczna: " << p1.getAsNumber() << " wartosc docelowa: " << num << "  roznica:" << abs(p1.getAsNumber()-num) << std::endl;
    PhiExpression p2 = p1*(2.0);
    PhiExpression p3 = p2-p1;
    std::cout << p3 << endl;
    return 0;
}