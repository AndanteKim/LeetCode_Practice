class Solution {
public:
    int hammingWeight(uint32_t n) {
        long steps = 0;
        while (n != 0){
            ++steps;
            n &= (n--);
        }
        
        return steps;
    }
};