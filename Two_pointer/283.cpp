class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int first_zero = -1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != 0 && first_zero != -1) {
                int tmp = nums[i];
                nums[i] = nums[first_zero];
                nums[first_zero] = tmp;
                first_zero ++;
            } else if (nums[i] == 0 && first_zero == -1) {
                first_zero = i;
            }
        }
    }
};