class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length()));
        for(int gap=0; gap<s.length(); gap++) {
            for(int start=0; start+gap < s.length(); start++) {
                if(gap==0) dp[start][start]=1;
                else {
                    if(s[start] == s[start+gap]) {
                        dp[start][start+gap] = dp[start+1][start+gap-1] + 2;
                    }
                    else {
                        dp[start][start+gap] = max(dp[start+1][start+gap], dp[start][start+gap-1]);
                    }
                }
                // cout<<start<<' '<<start+gap<<' '<<dp[start][start+gap]<<'\n';
            }
        }
        return dp[0][s.length()-1];
    }
};