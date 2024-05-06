

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int s = 0;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int e = sum;
        int ans = 0;
        int mid = (s + e) / 2;
        while (s <= e) {
            if (isPossible(nums, n, k, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
            mid = (s + e) / 2;
        }
        return ans;
    }
    
    bool isPossible(vector<int>& nums, int n, int k, int mid) {
        int subCount = 1;
        int subSum = 0;
        for (int i = 0; i < n; i++) {
            if (subSum + nums[i] <= mid)
                subSum += nums[i];
            else {
                subCount++;
                if (subCount > k || nums[i] > mid)
                    return false;
                subSum = nums[i];
            }
        }
        return true;
    }
};