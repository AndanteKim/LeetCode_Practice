class Solution {
public:
    int tribonacci(int n) {
        if (n <= 2)
            return n == 2? 1 : n == 1? 1 : 0;
        
        int t0 = 0, t1 = 1, t2 = 1, t3;
        for (int i = 0; i <= n - 3; ++i){
            t3 = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = t3;
        }
        
        return t3;
    }
};