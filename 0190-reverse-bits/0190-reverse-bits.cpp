class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int power = 31;
        
        for (int i = 0; i < 32; ++i){
            ans += (n & 1) * pow(2, power--);
            n >>= 1;
        }
        
        return ans;
    }
};