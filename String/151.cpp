class Solution {
public:
    string reverseWords(string s) {
        string cur = "";
        string answer = "";
        stack<string> stk;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == ' ') {
                if(cur == "") {
                    continue;
                } else {
                    stk.push(cur);
                    cur = "";
                }
            } else {
                cur += s[i];
            }
        }
        if(cur != "") stk.push(cur);
        while(true) {
            string top = stk.top();
            stk.pop();
            answer += top;
            if(stk.empty()) break;
            answer += ' ';
        }
        return answer;
    }
};