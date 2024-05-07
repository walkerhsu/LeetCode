class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rec = 0;
        vector<int> height(matrix[0].size()+1);
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[i].size(); j++) {
                if(matrix[i][j] == '0') height[j] = 0;
                else if(i==0) {
                    height[j] = 1;
                } else {
                    height[j] += 1;
                }
            }
            rec = max(rec , maxRectArea(height));
        }
        return rec;
    }

    int maxRectArea(vector<int> height) {
        height[height.size()-1] = -1;
        // cout<<height.size()<<' ';
        int res = 0;
        stack<int> stack_idx;
        for(int i=0; i<height.size(); i++) {
            while(!stack_idx.empty() && height[stack_idx.top()] > height[i]) {
                int top = stack_idx.top();
                stack_idx.pop();
                res = max(res, height[top] * (stack_idx.empty() ? i : (i - stack_idx.top() - 1)));
            }
            stack_idx.push(i);
            // cout<<res<<' ';
        }
        return res;
    }
};