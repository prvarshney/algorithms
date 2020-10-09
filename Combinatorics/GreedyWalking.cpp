// UCV2013E - Greedy Walking - https://www.spoj.com/problems/UCV2013E/
#include <iostream>

#define mod 1000000007
using namespace std;
typedef long long int BigInt;

BigInt power(BigInt a, BigInt x) {
    if(x == 0) return 1;
    if(x == 1) return a;
    BigInt temp = power(a, x / 2);
    temp = (temp * temp) % mod;

    if(x & 1 > 0)   // CHECKING FOR ODD POWERS
        return (temp * a) % mod;
    else 
        return temp;
}

BigInt combination(BigInt n, BigInt k, BigInt factorial[], BigInt inverse[]) {
    BigInt res = factorial[n];
    res = (res * inverse[n - k]) % mod;
    res = (res * inverse[k]) % mod;
    return res;
}

int main(int argc, char* argv[]) {
    // OPTIMISING IO OPERATIONS FROM STDIO
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // BINDING STDIO TO FILES
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // GENERATING FACTORIALS
    int maxm = 25000;
    BigInt factorial[maxm + 10];
    factorial[0] = 1;
    for(int iter = 1; iter <= maxm ; iter++)
        factorial[iter] = (factorial[iter - 1] * iter) % mod;
    // CALCULATING INVERSE FACTORIAL USING FERMAT'S LITTLE THEOREM
    BigInt inverse[maxm + 10];
    for(int iter = 0; iter <= maxm ; iter++) 
        inverse[iter] = power(factorial[iter], mod - 2) % mod;

    // TAKING INPUT FROM CONSOLE
    int n;
    while(cin >> n) {
        if(n == 0)  
            return 0;

        int x[n], y[n];
        for(int idx = 0 ; idx < n ; idx++)
            cin >> x[idx];
        for(int idx = 0 ; idx < n ; idx++)
            cin >> y[idx];
        
        int sum = 0;
        for(int idx = 0 ; idx < n ; idx++)
            sum += abs(x[idx] - y[idx]);
        
        BigInt res = 1;
        for(int idx = 0 ; idx < n ; idx++) {
            int r = abs(x[idx] - y[idx]);
            res = (res * combination(sum, r, factorial, inverse)) % mod;
            sum -= r;
        }

        cout << res << endl;
    }
}