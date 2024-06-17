class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 2; i * i <= c; ++i){
            int count = 0;
            
            if (c % i == 0){
                while (c % i == 0){
                    ++count;
                    c /= i;
                }
                
                if ((count % 2) && (i % 4 == 3))
                    return false;
            }
            
        }
        
        return c % 4 != 3;
    }
};