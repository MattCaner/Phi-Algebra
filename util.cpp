#include"util.hpp"

int MinIndex(double tab[], int size){
    int midex = 0;
    for(int i = 0; i<size; i++){
        if(tab[midex]>tab[i]) midex = i;
    }
    return midex;
}

bool Jump(double target, int* P, int* R,double phi_){
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
            *P += 1;
        break;
        case 2:
            *P -= 1;
        break;
        case 3:
            *R += 1;
        break;
        case 4:
            *R -= 1;
        break;
    }
    return 1;
}