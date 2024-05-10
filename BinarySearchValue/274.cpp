class Solution {
public:
    int hIndex(vector<int>& citations) {
        int max = -1;
        int min = 1001;
        for(int i=0; i<citations.size(); i++) {
            if(citations[i] > max) max = citations[i];
            if(citations[i] < min) min = citations[i];
        }
        vector<bool> passMid(citations.size(), true);
        int mid = (max + min) / 2;
        bool higher = true;
        int cnt = citations.size();
        int curMax = cnt;
        BinarySearch(citations, min, max, mid, cnt, curMax, higher, passMid);
        return curMax;
    }

    void BinarySearch (vector<int>& citations, int& min, int& max, int& mid, int& cnt, int& curMax, bool& higher, vector<bool>& passMid) {
        // cout<<min<<' '<<mid<<' '<<max<<':'<<curMax<<'\n';
        if(min > max) return;
        for(int i=0; i<citations.size(); i++) {
            if(higher && passMid[i]) {
                if(citations[i] < mid) {
                    cnt--;
                    passMid[i] = false;
                }
            } else if(!higher && !passMid[i]) {
                if(citations[i] >= mid) {
                    cnt++;
                    passMid[i] = true;
                }
            }
        }
        // cout<<cnt<<'\n';
        if(cnt >= mid) {
            curMax = mid;
            min = mid+1;
            mid = (min+max)/2;
            higher = true;
            BinarySearch(citations, min, max, mid, cnt, curMax, higher, passMid);
        } else if(cnt < mid) {
            max = mid-1;
            mid = (min+max)/2;
            higher = false;
            BinarySearch(citations, min, max, mid, cnt, curMax, higher, passMid);
        } else {
            return ;
        }
    }
};