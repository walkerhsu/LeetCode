class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> mask(nums.size(), false);
        vector<vector<int>> answer;
        vector<int> current;
        recursivePermute(nums, current, mask, answer);
        return answer;
    }

    void recursivePermute(vector<int>& nums, vector<int>& cur, vector<bool>& mask, vector<vector<int>>& answer) {
        if(cur.size() == nums.size()) {
            answer.push_back(cur);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(!mask[i]) {
                cur.push_back(nums[i]);
                mask[i] = true;
                recursivePermute(nums, cur, mask, answer);
                cur.pop_back();
                mask[i] = false;
            }
        }
        return;
    }
};