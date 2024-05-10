class Solution {
public:
    int candy(vector<int>& ratings) {
        int candies = ratings.size();
        int breaking_idx = 0;
        int falling_idx = 0;
        int falling_highest = -1;
        int last_candy = 0;
        for(int i=1; i<ratings.size(); i++) {
            if(ratings[i] > ratings[i-1]) {
                candies += (last_candy+1);
                last_candy++;
                breaking_idx = i;
                falling_highest = -1;
            } else if (ratings[i] == ratings[i-1]) {
                breaking_idx = i;
                last_candy = 0;
                falling_highest = -1;
            }
            else if (ratings[i] < ratings[i-1]) {
                if(falling_highest == -1) falling_highest = last_candy;
                last_candy = 0;
                falling_idx = i;
                if(falling_highest > falling_idx-breaking_idx-1) candies += (falling_idx-breaking_idx-1);
                else candies += (falling_idx-breaking_idx);
            }
            // cout<<candies<<'\n';
        }
        return candies;
    }
};