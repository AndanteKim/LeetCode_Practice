class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), ans = INT_MAX, total = 0;
        unordered_map<int, int> suffix;
        for (int i = n - 1; i >= 0; --i){
            total += nums[i];
            suffix[total] = i + 1;
            if (total == x) ans = min(ans, n - i);
        }
        
        total = 0;
        for (int i = 0; i < n; ++i){
            total += nums[i];
            if (total == x) ans = min(ans, i + 1);
            if (suffix[x - total] != 0 && suffix[x - total] - 1 > i)
                ans = min(ans, i + 1 + n - suffix[x - total] + 1);
        }
        
        return ans == INT_MAX? -1 : ans;
    }
};