// SPOJ PROBLEM - SKLINE - https://www.spoj.com/problems/SKYLINE/
#include <iostream>

#define mod 1000000

using namespace std;
typedef long long int BigInt;

BigInt power(int a, int x) {
    if(x == 0) return 1;
    if(x == 1) return a;
    BigInt temp = power(a, x / 2);
    temp = (temp * temp) % mod;
    if(x & 1 > 0)   // CHECK FOR ODD POWER
        return (temp * a) % mod;
    else 
        return temp;
}

BigInt inverse(BigInt x) {
    
}

int main(int argc, char* argv[]) {
    // OPTIMISING IO OPERATIONS FROM STDIO
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // TAKING INPUT FROM CONSOLE
    int n, maxm = 1000, factorial[2*maxm + 100];
    
    // PRECOMPUTING FACTORIAL NUMBERS UPTO 2*MAXM + 100
    factorial[0] = 1;
    for(int idx = 1; idx < 2*maxm + 100 ; idx++)
        factorial[idx] = (factorial[idx - 1] * idx) % mod;
    while(cin >> n) {
        if(n == 0)
            return 0;

        BigInt res = factorial[2 * n];
        res = res * power(inverse(factorial[n]), 2);  
        res = (double)res * (1 / (n + 1)) + 0.5f;
        cout << res << "\n";
    }
    return 0;
}