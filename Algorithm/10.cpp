class Solution {
public:
    string concise(string p) {
        int p_index = 0;
        string last_pair = "";
        string concise_p = "";
        while(p_index < p.length()) {
            // .*
            if(p[p_index] == '.' && p[p_index+1] == '*') {
                if(last_pair != ".*") {
                    concise_p += ".*";
                } 
                last_pair = ".*";
                p_index += 2;
            }
            // ?*
            else if(p[p_index+1] == '*') {
                if((last_pair.length() != 2) || (last_pair[0] != (p[p_index])) || (last_pair[1] != '*')) {
                    concise_p += p[p_index];
                    concise_p += '*';
                } 
                last_pair = p[p_index];
                last_pair += '*';
                p_index += 2;
            }
            else {
                concise_p += p[p_index];
                last_pair += p[p_index];
                p_index ++ ;
            }
        }
        return concise_p;
    }
    bool isMatch(string s, string p, bool need_concise=true) {
        if (need_concise) p = concise(p);
        if (s==p) return true;
        int s_index = 0;
        int p_index = 0;
        bool answer = true;
        while((s_index < s.length() && p_index < p.length())) {
            // ".*"
            if(p[p_index] == '.' && ((p_index+1) < p.length() && p[p_index+1] =='*') ) {
                if( p_index+2 == p.length() ) {
                    return true;
                }
                if(isMatch(s.substr(s_index), p.substr(p_index+2), false)  ) return true;
                while(s_index<s.length()) {
                    if( isMatch(s.substr(s_index+1), p.substr(p_index+2), false) ) {
                            return true;
                    }
                    s_index++;
                }
                return false;
            }

            // "?*"
            if(((p_index+1) < p.length() && p[p_index+1] =='*') ) {
                if((p_index+2) == p.length()) {
                    for(int i=s_index; i<s.length(); i++) {
                        if(s[i]!=p[p_index]) return false;
                    }
                    return true;
                }
                for(int i=s_index; i<s.length(); i++) {
                    if(s[i] != p[p_index]) {
                        break;
                    }
                    if(isMatch(s.substr(i+1), p.substr(p_index+2), false) ) {
                            return true;
                    }
                }
                return isMatch(s.substr(s_index), p.substr(p_index+2), false);
            }

            // "match"
            else if((s[s_index] == p[p_index]) || p[p_index]=='.') {
                s_index++ ;
                p_index++ ;
            }
            
            // does not match
            else {
                return false;
            }
        }
        if(s_index == s.length() && p_index == p.length()) return true;
        if(s_index == s.length()) {
            if((p.length() - p_index) % 2 != 0) return false;
            while(p_index < p.length()) {
                if(p[p_index+1] != '*') {
                    return false;
                }
                p_index += 2;
            }
            return true;
        }
        return false;
    }
};