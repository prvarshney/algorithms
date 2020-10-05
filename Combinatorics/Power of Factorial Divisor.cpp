#include <iostream>
#include <climits>

using namespace std;
int getPrimePower(int n, int k) {
    // ASSUMING K IS PRIME NUMBER HERE
    int cnt = 0;
    while(n) {
        cnt += n / k;
        n /= k;
    }
    return cnt;
}

int getCompositePower(int n, int k) {
    // ASSUMING K IS A COMPOSITE NUMBER HERE
    int originalNumber = n;
    int res = INT_MAX;
    for(int factor = 2; factor*factor <= k ; factor++) {
        int cnt = 0;
        while(k % factor == 0) {
            k /= factor;
            cnt += 1;
        }

        if(cnt > 0) // THAT MEANS FACTOR IS REALLY A FACTOR OF N
            res = min(res, getPrimePower(originalNumber, factor) / cnt);
    }

    // IF ELEMENT IS PRIME ON ITS OWN
    if(k > 1)
        res = min(res, getPrimePower(originalNumber, k));

    return res;
}

int
main(int argc, char* argv[]) {
    // OPTIMISING IO FROM STDIN
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    // READING INPUT FROM CONSOLE
    int n, k;
    cin >> n >> k;
    // PRODUCING OUTPUT
    cout << getCompositePower(n, k) << endl;
    return 0;
}