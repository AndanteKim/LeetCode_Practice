class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), start = 0, frequencyWithCharsOverK = 0;
        unordered_map<int, int> frequency;
        
        for (int end = 0; end < n; ++end){
            ++frequency[nums[end]];
            
            if (frequency[nums[end]] == k + 1)
                ++frequencyWithCharsOverK;
            
            if (frequencyWithCharsOverK){
                --frequency[nums[start]];
                if (frequency[nums[start]] == k)
                    --frequencyWithCharsOverK;
                ++start;
            }
        }
        
        return n - start;
    }
};