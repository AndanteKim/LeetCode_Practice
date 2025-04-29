class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size(), start = 0, maxElement = *max_element(nums.begin(), nums.end());
        vector<int> indicesOfMaxElement;

        for (int i = 0; i < n; ++i){
            if (nums[i] == maxElement) indicesOfMaxElement.push_back(i);

            int freq = indicesOfMaxElement.size();

            if (freq >= k)
                ans += indicesOfMaxElement[freq - k] + 1;
        }

        return ans;
    }
};