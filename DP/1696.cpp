class Solution {
public:
    const int MINIMUM = -pow(10,9);
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[n-1] = nums[n-1];
        int max_dp_idx = n-1;
        for(int i=n-2; i>=0; i--) {
            if(max_dp_idx - i <= k) {
                dp[i] = dp[max_dp_idx] + nums[i];
                if(nums[i] >= 0) {
                    max_dp_idx = i;
                }
            } else {
                int curMax = MINIMUM;
                for(int j=i+1; j<=i+k; j++) {
                    if (j >= n) break;
                    if(curMax < dp[j]+nums[i]) {
                        curMax = dp[j]+nums[i];
                    }
                }
                dp[i] = curMax;
                max_dp_idx = max(max_dp_idx, dp[i]);
            }
        }
        return dp[0];
    }
};