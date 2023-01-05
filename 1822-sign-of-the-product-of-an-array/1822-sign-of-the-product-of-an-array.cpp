class Solution {
public:
    int signFunc(long long res){
        return res > 0? 1 : res < 0? -1: 0;
    }
    
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == 0) return 0;
            else ans *= signFunc(nums[i]);
        }
        return ans;
    }
};