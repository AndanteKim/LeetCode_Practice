class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxElementInWindow = 0, maxElement = *max_element(nums.begin(), nums.end()), start = 0;
        long long ans = 0;
        
        for (int end = 0; end < n; ++end){
            if (nums[end] == maxElement) ++maxElementInWindow;

            while (maxElementInWindow == k){
                if (nums[start] == maxElement) --maxElementInWindow;
                ++start;
            }

            ans += start;
        }

        return ans;
    }
};