// FINDING CATALAN NUMBER USING RECURSIVE APPROACH
#include <iostream>

using namespace std;

int catalan(int n, int dp[]) {
    if(n == 0 || n == 1)
        return dp[n] = 1;
    if(dp[n] != 0)
        return dp[n];

    dp[n] = 0;
    for(int iter = 0 ; iter < n ; iter ++) 
        dp[n] += catalan(iter, dp) * catalan(n - 1 - iter, dp);
    return dp[n];
}

int main(int argc, char* argv[]) {
    // OPTIMISING IO OPERATIONS FROM STDIO
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // TAKING INPUT FROM CONSOLE
    int n;
    cin >> n;
    int dp[n + 1];
    fill_n(dp, n + 1, 0);
    dp[0] = dp[1] = 1;
    
    catalan(n, dp);

    // DISPLAYING CATALAN NUMBERS UPTO N
    for(int idx = 0 ; idx <= n ; idx++)
        cout << dp[idx] << " ";
    cout << endl;
    return 0;
}