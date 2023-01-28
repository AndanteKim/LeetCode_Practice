class Solution {
    int atMost(vector<int>& nums, int k){
        int ans = 0, left = 0;
        
        for (int right = 0; right < nums.size(); ++right){
            k -= nums[right] & 1;
            while (k < 0){
                k += nums[left] & 1;
                ++left;
            }
            ans += right - left + 1;
        }
        return ans;
    }
    
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};