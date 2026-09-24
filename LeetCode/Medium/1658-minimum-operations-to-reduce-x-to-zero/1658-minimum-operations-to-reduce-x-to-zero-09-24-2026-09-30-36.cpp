class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), curr = 0;
        int left = 0, longest = -1;
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        for (int right = 0; right < n; ++right) {
            curr += nums[right];
            
            while (left <= right && curr > total - x) {
                curr -= nums[left++];
            }

            if (curr == total - x) longest = max(longest, right - left + 1);
        }

        return longest != -1? n - longest : -1;
    }
};