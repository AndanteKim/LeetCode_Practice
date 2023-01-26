class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missed = nums.size();
        
        for (int i = 0; i <nums.size();++i) missed ^= (i ^ nums[i]);
        
        return missed;
    }
};