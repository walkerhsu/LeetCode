class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(int i=days.size()-1; i>=0; i--) {
            days[i] -= (days[0]-1);
            // cout<<days[i]<<' ';
        }
        // cout<<'\n';
        int max = days[days.size()-1];
        vector<int> dp(max+1);
        int idx = days.size()-2;
        dp[max] = min(min(costs[0], costs[1]), costs[2]);
        // cout<<dp[max]<<'\n';
        for(int i=max-1; i>=1; i--) {
            if(i == days[idx]) {
                int one_day_cost = costs[0] + (i+1 > max ? 0 : dp[i+1]);
                int seven_day_cost = costs[1] + (i+7 > max ? 0 : dp[i+7]);
                int thirty_day_cost = costs[2] + (i+30 > max ? 0 : dp[i+30]);
                dp[i] = min(min(one_day_cost, seven_day_cost), thirty_day_cost);
                idx--;
            } else {
                dp[i] = dp[i+1];
            }
            // cout<<dp[i]<<'\n';
        }
        return dp[1];
    }
};