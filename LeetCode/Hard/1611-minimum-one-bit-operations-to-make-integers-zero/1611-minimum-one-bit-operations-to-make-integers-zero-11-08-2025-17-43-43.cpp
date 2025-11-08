class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = n;

        for (int bin = 16; bin >= 1; bin >>= 1) {
            ans ^= (ans >> bin);
        }

        return ans;
    }
};