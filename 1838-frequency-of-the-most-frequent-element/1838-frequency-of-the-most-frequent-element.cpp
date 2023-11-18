class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        long curr = 0;
        
        for (int right = 0; right < nums.size(); ++right){
            long target = nums[right];
            curr += target;
            
            if (target * (right - left + 1) - curr > k)
                curr -= nums[left++];
        }
        
        return nums.size() - left;
    }
};