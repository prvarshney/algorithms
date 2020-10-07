#include <iostream>
#include <climits>

using namespace std;
int 
getPower(int n, int k) {
    int cnt = 0;
    while(n) {
        cnt += n / k;
        n /= k;
    }

    return cnt;
}

int 
main(int argc, char* argv[]) {
    // OPTIMISING IO FROM STDIO
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    // TAKING INPUT FROM CONSOLE
    int n, k;   // WE NEED TO FIND THE MAX. VALUE OF X SUCH THAT, N! % K^X == 0
    cin >> n >> k;
    int x = INT_MAX;
    // FINDING PRIME FACTORS OF K
    for(int iter = 2 ; iter * iter <= k ; iter ++) {
        int cnt = 0;
        if(k % iter == 0) {
            cnt += 1;
            k /= iter;
        }

        if(cnt)
            x = min(x, getPower(n, iter) / 2) ;
    }
    // IF K IS PRIME ON ITS OWN OR ANY FACTOR LEFT
    if(k > 1)
        x = min(x, getPower(n, k));
    
    // DISPLAYING ANSWER
    cout << x << endl;
    return 0;
}