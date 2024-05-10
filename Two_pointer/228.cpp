class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        vector<string> answers;
        int first = nums[0];
        int last = nums[0];
        string answer = "";
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != last+1) {
                if(first==last) {
                    answer = to_string(first);
                } else {
                    answer = to_string(first) + "->" + to_string(last);
                }
                answers.push_back(answer);
                answer = "";
                first = nums[i];
                last = nums[i];
            } else {
                last++;
            }
        }
        if(first==last) {
            answer = to_string(first);
        } else {
            answer = to_string(first) + "->" + to_string(last);
        }
        answers.push_back(answer);
        return answers;
    }
};