class Solution {
private:
    int k;
    int totalWays(int i, vector<int>& memo){
        if (i == 1)
            return k;
        if (i == 2)
            return k * k;
        
        if (memo[i] != -1)
            return memo[i];
        
        // Use the recurrence relation to calculate totalWays(i)
        return memo[i] = (k - 1) * (totalWays(i - 1, memo) + totalWays(i - 2, memo));
    }
    
public:
    int numWays(int n, int k) {
        this -> k = k;
        vector<int> memo(n + 1, -1);
        return totalWays(n, memo);
    }
};