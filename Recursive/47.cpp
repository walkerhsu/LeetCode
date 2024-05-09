class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> mask(nums.size(), false);
        set<vector<int>> answer;
        vector<int> current;
        recursivePermute(nums, current, mask, answer);
        vector<vector<int>> answer_vector(answer.begin(), answer.end());
        return answer_vector;
    }

    void recursivePermute(vector<int>& nums, vector<int>& cur, vector<bool>& mask, set<vector<int>>& answer) {
        if(cur.size() == nums.size()) {
            answer.insert(cur);
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