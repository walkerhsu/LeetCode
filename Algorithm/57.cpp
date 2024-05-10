class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int new_start = newInterval[0];
        int new_end = newInterval[1];
        bool start_found = false;
        bool end_found = false;
        bool lock = false;
        bool found = false;
        bool push_cur = false;
        for(int i=0; i<intervals.size(); i++) {
            if(!found && !start_found){
                if(new_start >= intervals[i][0] && new_start <= intervals[i][1]) {
                    newInterval[0] = intervals[i][0];
                    start_found = true;
                    lock = true;
                } else if (new_start < intervals[i][0]) {
                    start_found = true;
                    lock = true;
                }
            }
            if(!found && !end_found){
                if(new_end >= intervals[i][0] && new_end <= intervals[i][1]) {
                    newInterval[1] = intervals[i][1];
                    end_found = true;
                    push_cur = false;
                } else if (new_end < intervals[i][0]) {
                    end_found = true;
                    push_cur = true;
                }
            }
            if(!lock) {
                answer.push_back(intervals[i]);
            }
            if(end_found) {
                answer.push_back(newInterval);
                lock = false;
                if(push_cur) {
                    answer.push_back(intervals[i]);
                }
                end_found = false;
                found = true;
            }
        }
        if(!found) {
            answer.push_back(newInterval);
        }
        return answer;
    }
};