class Solution {
public:
    const char INITIAL = '0';
    const char REACHABLE = '1';
    const char UNREACHABLE = '2';

    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.length()-1] == '1') return false;
        vector<bool> dp(s.length());
        dp[0] = true;
        for(int i=1; i<minJump; i++) {
            dp[i] = false;
        }

        queue<int> canJump;
        canJump.push(0);
        for(int i=minJump; i<s.length(); i++) {
            if(canJump.front() == i-maxJump-1) {
                canJump.pop();
            }
            if(canJump.empty()) return false;
            if(s[i] == '1') dp[i] = false;
            else {
                if((i-canJump.front() <= maxJump) && (i-canJump.front() >= minJump)) dp[i] = true;
                else dp[i] = false;
            }
            if(s[i] == '0' && dp[i]) canJump.push(i);
        }
        return dp[s.length()-1];
    }
};