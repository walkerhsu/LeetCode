class Solution {
public:
    struct Point{
        int x;
        int y;
    };
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    explore(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
    void explore(vector<vector<char>>& grid, int cury, int curx) {
        stack<Point> s;
        Point p(curx, cury);
        s.push(p);
        while(!s.empty()) {
            Point top = s.top();
            // cout<<top.y<<' '<<top.x<<'\n';
            s.pop();
            grid[top.y][top.x] = '2';
            if(top.y != 0 && grid[top.y-1][top.x] == '1') {
                Point tmp(top.x, top.y-1);
                s.push(tmp);
            }
            if(top.y != grid.size()-1 && grid[top.y+1][top.x] == '1') {
                Point tmp(top.x, top.y+1);
                s.push(tmp);
            }
            if(top.x != 0 && grid[top.y][top.x-1] == '1') {
                Point tmp(top.x-1, top.y);
                s.push(tmp);
            }
            if(top.x != grid[top.y].size()-1 && grid[top.y][top.x+1] == '1') {
                Point tmp(top.x+1, top.y);
                s.push(tmp);
            }
        }
        return ;
    }
};