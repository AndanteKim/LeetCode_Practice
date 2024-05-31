class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Difference between two numbers (x and y) which were seen only once
        int bitmask = 0;
        for (int num:nums)
            bitmask ^= num;
        
        // Rightmost 1-bit diff between x and y
        unsigned int diff = bitmask & -(unsigned int)bitmask;
        int x = 0;
        
        for (int num : nums){
            // bitmask which will contain only x
            if (diff & num)
                x ^= num;
        }
        
        return vector<int>{x, bitmask ^ x};
    }
};