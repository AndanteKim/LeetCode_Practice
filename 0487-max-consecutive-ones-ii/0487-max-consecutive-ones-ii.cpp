class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, left = 0;
        bool flip = false;
        for (int right = 0; right < nums.size(); ++right){
            if (nums[right] == 0){
                if (!flip)
                    flip = true;
                else{
                    while(left < right && nums[left] != 0)
                        ++left;
                    ++left;
                }
            }
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};