class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, ans = 0;
        unordered_map<int, int> freq;

        for (int right = 0; right < n; ++right) {
            ++freq[nums[right]];
            
            while (right - left + 1 >= k && freq[nums[right]] > k) {
                --freq[nums[left++]];
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};