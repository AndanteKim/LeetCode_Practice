class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int i = 0; i <= n - k; ++i) {
            unordered_set<int> seen;
            for (int j = i; j < i + k; ++j) seen.insert(nums[j]);
        
            for (int num : seen) ++freq[num];
        }
        
        int ans = -1;
        for (const auto& [num, cnt] : freq) {
            if (cnt == 1) ans = max(ans, num);
        }

        return ans;
    }
};