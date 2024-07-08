class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        
        for (int i = 2; i <= n; ++i)
            ans = (ans + k) % i;
        
        // Add 1 to convert back to 1-indexing
        return ans + 1;
    }
};