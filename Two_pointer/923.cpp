class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long long int> m; 
        int max = -1;
        int min = 101;
        long long int answer = 0;
        for(int i=0; i<arr.size(); i++) {
            m[arr[i]] += 1;
            if (arr[i] > max) {
                max = arr[i];
            }
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        int big_pt = max;
        while(big_pt>=min) {
            int target2 = target - big_pt;
            int medium_pt = target2 > big_pt ? big_pt : target2 ;
            while(medium_pt>=(target2+1)/2) {
                int small_pt = target2-medium_pt;
                if(big_pt == medium_pt && medium_pt == small_pt) {
                    answer += ((m[big_pt] * (m[big_pt]-1) * (m[big_pt]-2)) / 6) % (1000000007);
                }else if(big_pt == medium_pt) {
                    answer += ((m[big_pt] * (m[big_pt]-1))/2 * m[small_pt]) % (1000000007);
                }else if(big_pt == small_pt) {
                    answer += ((m[big_pt] * (m[big_pt]-1))/2 * m[medium_pt]) % (1000000007);
                }else if(small_pt == medium_pt) {
                    answer += ((m[small_pt] * (m[small_pt]-1))/2 * m[big_pt]) % (1000000007);
                }else {
                    answer += (m[big_pt] * m[medium_pt] * m[small_pt] % 1000000007);
                }
                medium_pt--;
            }
            big_pt--;
        }
        return answer;
    }
};