class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int answer = nums.size()+1;
        int psum = 0;
        int left = 0;
        for(int right = 0; right< nums.size(); right++) {
            psum += nums[right];
            if(psum == target) {
                answer = min(answer, right-left+1);
            } else if(psum > target) {
                while(psum >= target) {
                    answer = min(answer, right-left+1);
                    psum -= nums[left];
                    left++;
                }
            }
        }
        if(answer == nums.size()+1) return 0;
        return answer;
    }
};