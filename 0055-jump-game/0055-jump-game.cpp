class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), lastPos = n - 1;
        
        for (int i = n - 1; i >= 0; --i){
            if (nums[i] + i >= lastPos)
                lastPos = i;
        }
        
        return lastPos == 0;
    }
};