class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0) return true;
        unordered_map<int, bool> idx_map;
        stack<int> idx_stack;
        idx_stack.push(start);
        while(!idx_stack.empty()) {
            int cur_idx = idx_stack.top();
            idx_stack.pop();
            idx_map[cur_idx] = 1;
            if(cur_idx + arr[cur_idx] < arr.size()) {
                if(arr[cur_idx + arr[cur_idx]] == 0) {
                    return true;
                } else if(idx_map[cur_idx + arr[cur_idx]] != 1) {
                    idx_stack.push(cur_idx + arr[cur_idx]);
                }
            }
            if(cur_idx - arr[cur_idx] >= 0) {
                if(arr[cur_idx - arr[cur_idx]] == 0) {
                    return true;
                } else if(idx_map[cur_idx - arr[cur_idx]] != 1)  {
                    idx_stack.push(cur_idx - arr[cur_idx]);
                }
            }
        }
        return false;
    }
};