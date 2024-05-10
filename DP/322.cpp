class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for(int i=1; i<=amount; i++) {
            for(int coin : coins) {
                if(i-coin < 0) continue;
                int change = dp[i-coin];
                if(change == -1) continue;
                dp[i] = (dp[i] == -1) ? change+1 : min(change+1, dp[i]);
            }
            // cout<<dp[i]<<'\n';
        }
        return dp[amount];
    }
};