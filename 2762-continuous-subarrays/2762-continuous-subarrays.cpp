typedef long long ll;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size(), left = 0;
        // Map to maintain sorted frequency map of current window
        map<int, int> freq;
        ll ans = 0;     // Total count of valid subarrays
        
        for (int right = 0; right < n; ++right){
            // Add current element to frequency map
            ++freq[nums[right]];
            
            // While window violates the condition |nums[i] - nums[j]| <= 2
            // Shrink window from left
            while (freq.rbegin() -> first - freq.begin() -> first > 2){
                // Remove leftmost element from frequency map
                --freq[nums[left]];
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                ++left;
            }
            
            // Add count of all valid subarrays ending at right
            ans += right - left + 1;
        }
        
        return ans;
    }
};