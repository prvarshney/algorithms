// PROBLEM - MAGIC OF THE LOCKER - https://www.spoj.com/problems/LOCKER/
#include <iostream>

#define mod 1000000007

using namespace std;
typedef long long int BigInt;

BigInt binpow(int n, BigInt power) {
    if(power == 0) return 1;
    if(power == 1) return n % mod;
    BigInt temp = binpow(n, power / 2);
    temp = (temp * temp) %  mod;
    
    if(power & 1 > 0)   // CHECK FOR ODD
        return (temp * n) % mod;
    else 
        return temp; 
}

int 
main(int argc,char* argv[]) {
    // OPTIMISING IO OPERATIONS
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ATTACHING IO WITH FILES
    freopen("inputs.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);
    // TAKING INPUT FROM CONSOLE
    int t;
    cin >> t; 
    while (t --) {
        BigInt n, asf = 1;
        cin >> n;
        if(n <= 3) {
            cout << n << "\n";
            continue;
        }

        if(n % 3 == 0) 
            asf = binpow(3, n / 3);
        else if(n % 3 == 1) 
            asf = (binpow(3, (n - 4) / 3) * 4) % mod;
        else 
            asf = (binpow(3, (n - 2) / 3) * 2) % mod;
        cout << asf << "\n";
    }
    return 0;
}