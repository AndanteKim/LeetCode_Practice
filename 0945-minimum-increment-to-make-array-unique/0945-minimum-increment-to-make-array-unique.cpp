class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, need = 0;
        
        for (int n:nums){
            ans += max(need - n, 0);
            need = max(need + 1, n + 1);
        }
        
        return ans;
    }
};