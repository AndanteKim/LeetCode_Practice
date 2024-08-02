class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ans = 0, counts1 = count(nums.begin(), nums.end(), 1), n = nums.size();
        
        for (int i = 0; i < counts1; ++i)
            if (nums[i] == 0) ++ans;
        
        int windowLength = ans;
        for (int left = 0; left < n; ++left){
            if (nums[(left + counts1) % n] == 0)
                ++windowLength;
            if (nums[left] == 0) --windowLength;
            
            ans = min(ans, windowLength);
        }
        
        return ans;
    }
};