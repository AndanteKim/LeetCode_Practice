class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int op = 0, op0 = 0, op1 = 0;
        
        for (int n:nums)
            op ^= n;
        
        for (int i = 1; i <= nums.size(); ++i)
            op ^= i;
        
        int rightBitMost = op & ~(op - 1);
        
        for (int n:nums){
            if ((n & rightBitMost) != 0)
                op1 ^= n;
            else
                op0 ^= n;
        }
        
        for (int i = 1; i <= nums.size(); ++i){
            if ((i & rightBitMost) != 0)
                op1 ^= i;
            else
                op0 ^= i;
        }
        
        for (int n:nums){
            if (n == op0)
                return vector<int>{op0, op1};
        }
        
        return vector<int>{op1, op0};
    }
};