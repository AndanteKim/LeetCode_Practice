class Solution {
public:
    int minFlips(int a, int b, int c) {
        if ((a | b) == c)
            return 0;
        
        int ans = 0, flip = 1, maxVal = max(a, max(b, c));
        while (flip <= maxVal){
            int aBit = a & 1, bBit = b & 1, cBit = c & 1;
            
            if (aBit == 1 && bBit == 1 && cBit == 1){
                flip <<= 1;
                a >>= 1;
                b >>= 1;
                c >>= 1;
                continue;
            }
            ans += abs(cBit - bBit - aBit);
            flip <<= 1;
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return ans;
    }
};