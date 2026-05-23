class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), invCnt = 0;
        if (n == 1) return true;

        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) ++invCnt;

            if (invCnt > 1) return false;
        }
        
        if (nums[0] < nums.back()) ++invCnt;
        return invCnt <= 1;
    }
};