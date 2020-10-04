// BINARY EXPONENTIAL IS AN ALGORITH BY USING WHICH WE CAN FIND THE EXPONENT OF A NUM IN O(LOGN) TIME COMPLEXITY
// WHERES NAIVE APPROACH IS OF O(N) TIME COMPLEXITY
#include <iostream>

using namespace std;
double
binpow(int a, int x) {
    if(x == 0) return 1;
    if(x == 1) return a;
    if(x < 0) return 1 / binpow(a, -x);

    double asf = binpow(a, x/2);
    if(x % 2 == 0)
        return asf * asf;
    else 
        return asf * asf * a;
}

int 
main(int argc, char* argv[]) {
    int a = 2, x = -3;
    cout << binpow(a, x);
    return 0;
}