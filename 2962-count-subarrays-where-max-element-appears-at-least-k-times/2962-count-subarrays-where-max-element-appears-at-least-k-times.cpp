class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int freq, maxElement = *max_element(nums.begin(), nums.end()), n = nums.size();
        vector<int> indicesOfMaxElements;
        
        for (int i = 0; i < n; ++i){
            if (nums[i] == maxElement)
                indicesOfMaxElements.push_back(i);
            
            freq = indicesOfMaxElements.size();
            if (freq >= k){
                ans += indicesOfMaxElements[freq - k] + 1;
            }
        }
        
        return ans;
    }
};