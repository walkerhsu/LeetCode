class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, n);
        // cout<<int(sqrt(10)) * sqrt(10)<<'\n';
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++) {
            if((int(sqrt(i)) * int(sqrt(i))) == i) {
                dp[i] = 1;
                // cout<<"square\n";
            }
            else {
                for(int j=1; j<=sqrt(i); j++) {
                    // cout<<(j*j)<<' '<<i-(j*j)<<'\n';
                    dp[i] = min(dp[i], dp[(j*j)] + dp[i-(j*j)]);
                }
            }
            // cout<<i<<' '<<dp[i]<<'\n';
        }
        return dp[n];
    }
};