// ADA AND TEAMS - https://www.spoj.com/problems/ADATEAMS/
#include <iostream>

#define mod 1000000007
#define maxm 1000100

using namespace std;
typedef long long int BigInt;

BigInt power(BigInt a, BigInt x) {
    if(x == 0) return 1;
    if(x == 1) return a;
    BigInt temp = power(a, x / 2);
    temp = (temp * temp) % mod;
    
    if( x & 1 > 0 )     // CHECKING FOR THE ODD POWER
        return (temp * a) % mod;
    else 
        return temp;
}

BigInt comb(int n, int r, BigInt factorial[]) {
    BigInt res = factorial[n];
    res = (res * power(factorial[n - r], mod - 2)) % mod;
    res = (res * power(factorial[r], mod - 2)) % mod;

    return res;
}

int main(int argc, char* argv[]) {
    // OPTIMISING IO FROM STDIO
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ATTACHING STDIN WITH INPUT.TXT
    // freopen("input.txt", "r", stdin);
    // PRECOMPUTING FACTORIALS
    BigInt factorial[maxm];
    factorial[0] = 1;
    for(int iter = 1; iter < maxm ; iter++)
        factorial[iter] = (factorial[iter - 1] * iter) % mod;
    // TAKING INPUT FROM CONSOLE
    int n, a, b, d;
    while(cin >> n) {
        cin >> a >> b >> d;
        BigInt nacomb, bdcomb, res;
        res = comb(n, a, factorial);
        res = (res * power(comb(b, d, factorial), a)) % mod;

        // DISPLAYING OUTPUT
        cout << res << "\n";
    }
    return 0;
}