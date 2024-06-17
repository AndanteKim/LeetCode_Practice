class Solution {
public:
    bool judgeSquareSum(int c) {
        
        int b = INT_MAX;
        for (int a = 0; a <= c && b >= a * a; ++a){
            b = c - (a * a);
            int sqrtB = sqrt(b);
            if (a * a + sqrtB * sqrtB == c) return true;
        }
        
        return false;
    }
};