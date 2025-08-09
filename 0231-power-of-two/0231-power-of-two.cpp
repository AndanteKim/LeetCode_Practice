class Solution {
public:
    bool isPowerOfTwo(int n) {
        long curr = 1;

        while (curr <= n){
            if (curr == n) return true;
            curr <<= 1;
        }

        return false;
    }
};