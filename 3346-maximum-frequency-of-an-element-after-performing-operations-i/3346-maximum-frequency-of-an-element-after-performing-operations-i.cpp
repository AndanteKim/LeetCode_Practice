class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> freqs;
        sort(nums.begin(), nums.end());
        for (const int num : nums) ++freqs[num];

        int left, right, curr;
        for (int i = nums[0]; i <= nums.back(); ++i){
            left = lower_bound(nums.begin(), nums.end(), i - k) - nums.begin();
            right = upper_bound(nums.begin(), nums.end(), i + k) - nums.begin();
            curr = min(right - left, freqs[i] + numOperations); 
            ans = max(ans, curr);
        }

        return ans;
    }
};