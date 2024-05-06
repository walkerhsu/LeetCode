class Solution {
public:
    int findMin(vector<int>& nums) {
        int first_idx = 0;
        int last_idx = nums.size()-1;
        if(nums.size()==1) return nums[0];
        if(nums[first_idx]<nums[last_idx]) return nums[first_idx];

        int cur_idx = (first_idx + last_idx) / 2;
        while(last_idx - first_idx != 1) {
            if ((nums[first_idx] == nums[last_idx]) && (nums[first_idx] == nums[cur_idx])) {
                for(int i=first_idx; i<cur_idx; i++) {
                    if(nums[i] < nums[first_idx]) {
                        return nums[i];
                    } else if (nums[i] > nums[first_idx]) {
                        return nums[first_idx];
                    }
                }
                first_idx = cur_idx;
            } 
            else if(nums[first_idx]<=nums[cur_idx]) {
                first_idx = cur_idx;
            } else if (nums[first_idx]>nums[cur_idx]) {
                last_idx = cur_idx;
            } 
            cur_idx = (first_idx + last_idx) / 2;
        }
        return min(nums[first_idx], nums[last_idx]);
    }
};