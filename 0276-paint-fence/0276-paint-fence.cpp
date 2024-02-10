class Solution {
public:
    int numWays(int n, int k) {
        if (n == 1) return k;
        if (n == 2) return k * k;
        
        vector<int> totalWays(n + 1);
        totalWays[1] = k, totalWays[2] = k * k;
        for (int i = 3; i <= n; ++i){
            totalWays[i] = (k - 1) * (totalWays[i - 1] + totalWays[i - 2]);
        }
        
        return totalWays[n];
    }
};