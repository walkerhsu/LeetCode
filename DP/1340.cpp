

class Solution {
public:
    const int PROCESSING = -1;
    const int INITIAL    = -2;
    int maxJumps(vector<int>& arr, int d) {
        vector<int> dp(arr.size(), INITIAL);
        int answer = 1;
        for(int i=0; i<arr.size(); i++) {
            dp[i] = jumpDP(arr, d, i, dp);
            answer = max(answer, dp[i]);
        }
        return answer;
    }

    int jumpDP(vector<int>& arr, int& d, int curIdx, vector<int>& dp) {
        if(dp[curIdx] != INITIAL && dp[curIdx] != PROCESSING) return dp[curIdx];
        int answer = 1;
        dp[curIdx] = PROCESSING;
        for(int j=curIdx-1; j>=curIdx-d; j--) {
            if(j<0) break;
            if(arr[j]>=arr[curIdx]) break;
            if(dp[j] == PROCESSING) continue;
            answer = max(answer, jumpDP(arr, d, j, dp)+1);
        }
        for(int j=curIdx+1; j<=curIdx+d; j++) {
            if(j>=arr.size()) break;
            if(arr[j]>=arr[curIdx]) break;
            if(dp[j] == PROCESSING) continue;
            answer = max(answer, jumpDP(arr, d, j, dp)+1);
        }
        dp[curIdx] = answer;
        return dp[curIdx];
    }
};