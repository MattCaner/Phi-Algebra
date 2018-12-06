#include"util.hpp"

int MinIndex(double tab[], int size){
    int midex = 0;
    for(int i = 0; i<size; i++){
        if(tab[midex]>tab[i]) midex = i;
    }
    return midex;
}

int GCD4(int a, int b, int c, int d){
    int tmp = GDC2(a,b);
    tmp = GDC2(tmp,c);
    tmp = GDC2(tmp,d);
    return tmp;     //can be also return GDC(GDC(GDC(a,b),c),d)
}
/**

int GDC2(int a, int b)
{ 
    if (a == 0) return b; 
    if (b == 0) return a; 
    if (a == b) return a; 

    if (a > b) return GDC2(a-b, b); 
    else return GDC2(a, b-a); 
} */

int GDC2(int u, int v) {
    while ( v != 0) {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}