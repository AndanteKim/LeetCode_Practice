class Solution {
public:
    int mySqrt(int x) {
        for (int i = 0; i <= x; ++i){
            if ((long)i * i >= x){
                if ((long)i * i == x)
                    return i;
                return i - 1;
            }
        }
        
        return -1;
    }
};