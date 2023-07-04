class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for (int shift = 0; shift < 32; ++shift){
            int bitSum = 0;
            for (int num : nums){
                bitSum += (num >> shift) & 1;
            }
            
            int lonerBit = bitSum % 3;
            ans = ans | (lonerBit << shift);
        }
        
        return ans;
    }
};