typedef long long ll;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll ans = 0, currSum = 0;
        int n = nums.size(), left = 0;
        unordered_map<int, int> freq;
        
        for (int right = 0; right < n; ++right){
            ++freq[nums[right]];
            currSum += nums[right];
            
            while (right - left >= k){
                --freq[nums[left]];
                if (freq[nums[left]] == 0) freq.erase(nums[left]);
                currSum -= nums[left++];
            }
            
            if (freq.size() == k)
                ans = max(ans, currSum);
        }
        
        return ans;
    }
};