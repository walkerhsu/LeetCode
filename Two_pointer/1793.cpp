class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int low_pt = k;
        int large_pt = k;
        int min = nums[k];
        int answer = 0;
        int num=2;
        if(nums.size()==1) {
            return nums[0];
        }
        while(num<=nums.size()) {
            if((low_pt-1) >= 0 && (large_pt+1)<nums.size()) {
                if(nums[low_pt-1] <= nums[large_pt+1] ) {
                    large_pt++;
                    if(nums[large_pt] < min) {
                        min = nums[large_pt];
                    }
                } else {
                    low_pt--;
                    if(nums[low_pt] < min) {
                        min = nums[low_pt];
                    }
                }
            } else if(low_pt == 0) {
                large_pt++;
                if(nums[large_pt] < min) {
                    min = nums[large_pt];
                }
            } else {
                low_pt--;
                if(nums[low_pt] < min) {
                    min = nums[low_pt];
                }
            } 
            if((min*num) > answer) {
                answer = min*num;
            }
            num += 1;
        }
        return answer;
    }
};