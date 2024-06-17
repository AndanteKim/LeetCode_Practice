class Solution {
public:
    bool judgeSquareSum(int c) {
        
        int b = INT_MAX;
        for (int a = 0; a <= c && b >= a * a; ++a){
            b = c - (a * a);
            
            double sqrtB = sqrt(b);
            if (sqrtB == (int)sqrtB) return true;
        }
        
        return false;
    }
};