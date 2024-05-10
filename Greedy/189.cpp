class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if(k==0) return ;
        int first_idx = 0;
        while(first_idx < nums.size()-k){
            for(int i=nums.size()-k; i<nums.size(); i++) {
                if(first_idx == nums.size()-k) {
                    k = nums.size() - i;
                    break;
                }
                swap(nums[first_idx], nums[i]);
                first_idx++;
            }
        }
    }
};