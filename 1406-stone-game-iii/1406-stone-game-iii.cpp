class Solution {
private:
    int n, notComputed = 1'000'000'000;
    int dp(int i, vector<int>& stoneValue, vector<int>& memo){
        if (i == this -> n) return 0;
        
        if (memo[i] != notComputed) return memo[i];
        
        memo[i] = stoneValue[i] - dp(i + 1, stoneValue, memo);
        if (i + 2 <= n) memo[i] = max(memo[i], stoneValue[i] + stoneValue[i + 1] - dp(i + 2, stoneValue, memo));
        if (i + 3 <= n) memo[i] = max(memo[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp(i + 3, stoneValue, memo));
        return memo[i];
    }
    
public:
    string stoneGameIII(vector<int>& stoneValue) {
        this -> n = stoneValue.size();
        vector<int> memo(n + 1, notComputed);
        int diff = dp(0, stoneValue, memo);
        return diff > 0? "Alice": diff < 0? "Bob" : "Tie";
    }
};