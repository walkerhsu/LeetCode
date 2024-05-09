class Solution {
public:
    struct Idx_info{
        int idx;
        int steps;
    };
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> number_list;
        for(int i=0; i<arr.size(); i++) {
            number_list[arr[i]].push_back(i);
        }
        vector<bool> hasPushed(arr.size(), false);
        queue<Idx_info> idx_queue;
        Idx_info first(0,0);
        idx_queue.push(first);
        hasPushed[0] = true;
        int max = arr.size()-1;
        while(max--) {
            Idx_info first = idx_queue.front();
            // cout<<first.idx<<' '<<first.steps<<'\n';
            for(int same_num_idx: number_list[arr[first.idx]]) {
                // cout<<same_num_idx<<' ';
                if(same_num_idx == arr.size()-1) {
                    return first.steps+1;
                } else if (!hasPushed[same_num_idx]) {
                    Idx_info next_idx(same_num_idx, first.steps+1);
                    idx_queue.push(next_idx);
                    hasPushed[same_num_idx] = true;
                }
            }
            number_list[arr[first.idx]] = {};
            // cout<<'\n';
            if (first.idx > 0 && !hasPushed[first.idx-1]) {
                Idx_info next_idx(first.idx-1, first.steps+1);
                idx_queue.push(next_idx);
                hasPushed[first.idx-1] = true;
            }
            if(first.idx+1 == arr.size()-1) {
                return first.steps+1;
            } else if (!hasPushed[first.idx+1]) {
                Idx_info next_idx(first.idx+1, first.steps+1);
                idx_queue.push(next_idx);
                hasPushed[first.idx+1] = true;
            }
            idx_queue.pop();
        }
        return arr.size()-1;
    }
};