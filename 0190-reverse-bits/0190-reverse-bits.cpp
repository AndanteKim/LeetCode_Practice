class Solution {
private:
    int reverseByte(int byte, map<uint32_t, uint32_t>& cache){
        if (cache.count(byte))
            return cache[byte];
        
        return cache[byte] = (byte * 0x0202020202 & 0x010884422010) % 1023;
    }
    
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int power = 24;
        map<uint32_t, uint32_t> cache;
        
        while (n > 0){
            ans += reverseByte(n & (0xFF), cache) << power;
            n >>= 8;
            power -= 8;
        }
        
        return ans;
    }
};