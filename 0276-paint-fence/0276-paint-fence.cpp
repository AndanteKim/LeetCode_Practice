class Solution {
public:
    int numWays(int n, int k) {
        // Space optimization with tabulation
        if (n == 1) return k;
        if (n == 2) return k * k;
        
        int twoPostsBack = k, onePostBack = k * k;
        for (int i = 3; i <= n; ++i){
            int curr = (k - 1) * (twoPostsBack + onePostBack);
            twoPostsBack = onePostBack;
            onePostBack = curr;
        }
        
        return onePostBack;
    }
};