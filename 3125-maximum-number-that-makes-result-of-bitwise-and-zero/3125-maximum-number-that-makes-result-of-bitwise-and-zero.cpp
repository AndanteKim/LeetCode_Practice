class Solution {
public:
    long long maxNumber(long long n) {
        long long msb = 0;
        
        while (msb < n){
            msb = msb * 2 + 1;
        }
        
        return msb >> 1;
    }
};