#include <iostream>

using namespace std;

double
binpow(double a, int x) {
    if(x < 0) return 1 / binpow(a, -x);

    double prod = 1;
    while( x > 0) {
        if(x & 1) prod = prod * a;
        a = a * a;
        x = x >> 1;
    }

    return prod;
}

int 
main(int argc, char* argv[]) {
    double a = 2;
    int b = -3;
    cout << binpow(a, b);
    return 0;
}