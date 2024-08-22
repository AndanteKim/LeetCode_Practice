class Solution {
public:
    int findComplement(int num) {
        long ans = 0, bitwise = 1;
        
        while (bitwise < num){
            if (!(num & bitwise))
                ans += bitwise;
            
            bitwise <<= 1;
        }
        
        return static_cast<int>(ans);
    }
};