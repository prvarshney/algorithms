#include <iostream>
#include <algorithm>

#define limit 100000000
using namespace std;
bool dp[limit + 10];


int main(int argc,char* argv[]) {
    // OPTIMISING IO OPERATIONS
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill_n(dp, limit, true); 
    for(int iter = 2; iter * iter < limit; iter ++) {
        if(dp[iter])
            for(int factor = iter * iter ; factor < limit ; factor += iter )
                dp[factor] = false;
    }

    int cnt = 0;
    for(int iter = 2; iter < limit ; iter ++)
        if(dp[iter]) {
            cnt += 1;
            if(cnt % 100 == 1)
                cout << iter << endl;
        }

    return 0;
}