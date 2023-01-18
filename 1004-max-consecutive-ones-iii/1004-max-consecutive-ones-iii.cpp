class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        
        for (right = 0; right < nums.size(); ++right){
            k -= 1 - nums[right];
            
            if (k < 0){
                k += 1 - nums[left];
                ++left;
            }
        }
        
        return right - left;
    }
};