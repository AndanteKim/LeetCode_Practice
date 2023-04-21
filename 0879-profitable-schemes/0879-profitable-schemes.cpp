class Solution {
    int memo[101][101][101];
    int mod = 1e9 + 7;
    int find(int pos, int count, int profit, int n, int minProfit, vector<int>& group, vector<int>& profits){
        if (pos == group.size()) return profit >= minProfit;
        
        if (memo[pos][count][profit] != -1) return memo[pos][count][profit];
        
        int totalWays = find(pos + 1, count, profit, n, minProfit, group, profits);
        if (count + group[pos] <= n)
            totalWays += find(pos + 1, count + group[pos], min(minProfit, profit + profits[pos]), n, minProfit, group, profits);
        return memo[pos][count][profit] = totalWays % mod;
    }
    
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(memo, -1, sizeof(memo));
        return find(0, 0, 0, n, minProfit, group, profit);
    }
};