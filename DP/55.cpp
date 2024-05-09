class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[nums.size()-1] = true;
        for(int i = nums.size()-1; i>=0; i--) {
            for(int j=0; j<=nums[i]; j++) {
                if(i+j>nums.size()-1) {
                    dp[i] = true;
                    break;
                } else if(dp[i+j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};