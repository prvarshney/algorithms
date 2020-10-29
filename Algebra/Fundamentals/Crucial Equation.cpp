#include <iostream>

using namespace std;
int 
gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int 
main(int argc, char* argv[]) {
    // OPTIMISING IO OPERATIONS
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // READING INPUT FROM FILES
    freopen("inputs.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);
    // TAKING INPUT FROM CONSOLE
    int t;
    cin >> t;
    for(int iter = 1; iter <= t ; iter++) {
        int a, b, c;
        cin >> a >> b >> c;
        int d = gcd(a, b);
        
        if(c % d == 0)
            printf("Case %d: Yes\n", iter);
        else
            printf("Case %d: No\n", iter);
    }
    return 0;
}