class Solution {
public:
    struct Diff{
        int start_idx;
        int total_diff;
    };
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> v(gas.size(), 0);
        queue<Diff> q;
        bool is_pos = (gas[0]-cost[0]) >= 0;
        int start = 0;
        int cur = (gas[0]-cost[0]);
        int sum = cur;
        for(int i=1; i<gas.size(); i++) {
            if((gas[i]-cost[i]>=0 && is_pos) || (gas[i]-cost[i]<0 && !is_pos)) {
                cur += gas[i]-cost[i];
            } else {
                Diff tmp(start, cur);
                q.push(tmp);
                is_pos = !is_pos;
                cur = gas[i]-cost[i];
                start = i;
            }
            sum += gas[i]-cost[i];
        }
        if(sum < 0) return -1;
        Diff tmp(start, cur);
        q.push(tmp);
        start = 0;
        cur = 0;
        while(!q.empty() && start != -1) {
            // cout<<start<<' '<<cur<<'\n';
            Diff front = q.front();
            q.pop();
            cur += front.total_diff;
            if(cur < 0) {
                Diff tmp(-1, cur);
                q.push(tmp);
                front = q.front();
                q.pop();
                start = front.start_idx;
                cur = front.total_diff;
                // cout<<start<<' '<<cur<<'\n';
            }
        }
        return start;
    }
};