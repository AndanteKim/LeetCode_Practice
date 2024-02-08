class Solution {
private:
    int isSquare(int n){
        int sq = sqrt(n);
        return sq * sq == n;
    }
    
public:
    int numSquares(int n) {
        // four-square and three-square theorems
        while ((n & 3) == 0)
            n >>= 2; // reducing the 4^k factor from number
        
        if ((n & 7) == 7) // mod 8
            return 4;
        
        if (isSquare(n))
            return 1;
        
        // check if the number can be decomposed into sum of two squares
        for (int i = 1; i <= (int)sqrt(n); ++i){
            if (isSquare(n - i * i))
                return 2;
        }
        
        // bottom case from the three-square theorem
        return 3;
    }
};