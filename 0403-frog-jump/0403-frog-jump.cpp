class Solution {
private:
    int dp[2001][2001];
    int n;
    int solve(vector<int>& stones, int index, int prevJump, unordered_map<int, int>& mark){
        if (index >= n - 1) return 1;
        if (dp[index][prevJump] != -1) return dp[index][prevJump];
        
        bool ans = false;
        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; ++nextJump){
            if (nextJump > 0 && mark.find(stones[index] + nextJump) != mark.end())
                ans = ans || solve(stones, mark[stones[index] + nextJump], nextJump, mark);
        }
        
        return dp[index][prevJump] = ans;
    }
    
public:
    bool canCross(vector<int>& stones) {
        this -> n = stones.size();
        memset(dp, -1, sizeof(dp));
        unordered_map<int, int> mark;
        
        for (int i = 0; i < n; ++i) mark[stones[i]] = i;
        return solve(stones, 0, 0, mark);
    }
};