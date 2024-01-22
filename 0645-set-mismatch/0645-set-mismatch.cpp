class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long diff = 0, sqDiff = 0;
        
        for (int i = 0; i < nums.size(); ++i){
            diff += (i + 1) - nums[i];
            sqDiff += (i + 1) * (i + 1) - nums[i] * nums[i];
        }
        
        int sum = sqDiff / diff;
        return vector<int>{(int)(sum - diff) >> 1, (int)(sum + diff) >> 1};
    }
};