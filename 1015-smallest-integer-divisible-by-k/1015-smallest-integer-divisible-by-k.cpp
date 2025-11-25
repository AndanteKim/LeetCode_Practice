class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int mod = 0;

        for (int lengthN = 1; lengthN <= k; ++lengthN) {
            mod = (mod * 10 + 1) % k;
            
            if (mod == 0) return lengthN;
        }

        return -1;
    }
};