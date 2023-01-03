class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1, tot = 0, rem;
        while (n != 0){
            rem = n % 10;
            prod *= rem;
            tot += rem;
            n /= 10;
        }
        
        return prod - tot;
    }
};