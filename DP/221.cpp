
class Solution {
    struct INFO {
        int left;
        int top;
        int best_square;
    };
    public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // left 1's, up 1,s, most_square
        vector<vector<INFO*>> squareInfo;
        int best = 0;
        for(int i=0; i<matrix.size(); i++) {
            squareInfo.push_back({});
            for(int j=0; j<matrix[i].size(); j++) {
                INFO* info = new INFO(0,0,0);
                if(matrix[i][j] == '0') {
                    info->left = 0;
                    info->top = 0;
                    info->best_square = 0;
                } else if(i==0 && j==0) {
                    info->left = 1;
                    info->top = 1;
                    info->best_square = 1;
                } else if(i==0) {
                    info->left = squareInfo[i][j-1]->left+1;
                    info->top = 1;
                    info->best_square = 1;
                } else if(j==0) {
                    info->left = 1;
                    info->top = squareInfo[i-1][j]->top+1;
                    info->best_square = 1;
                } else {
                    int largestSquare = min(min(squareInfo[i][j-1]->left, squareInfo[i-1][j]->top), squareInfo[i-1][j-1]->best_square)+1;
                    info->left = squareInfo[i][j-1]->left +1;
                    info->top = squareInfo[i-1][j]->top +1;
                    info->best_square = largestSquare;
                }
                squareInfo[i].push_back(info);
                if(squareInfo[i][j]->best_square > best) {
                    best = squareInfo[i][j]->best_square;
                }
            }
        }
        return best * best;
    }
};