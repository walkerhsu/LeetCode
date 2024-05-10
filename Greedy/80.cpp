class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastNum = nums[0];
        int duplicate = 1;
        int swapIdx = 1;

        for(int i=1; i<nums.size(); i++) {
            if(lastNum != nums[i]) {
                lastNum = nums[i];
                duplicate = 1;
            } else {
                duplicate++;
            }
            if (swapIdx != i) {
                int tmp = nums[i];
                nums[i] = nums[swapIdx];
                nums[swapIdx] = tmp;
            }
            if(duplicate<=2) {
                swapIdx++;
            }
            // cout<<swapIdx<<' ';
        }
        for(int i=nums.size(); i>swapIdx; i--) {
            nums.pop_back();
        }
        return swapIdx;
    }
};