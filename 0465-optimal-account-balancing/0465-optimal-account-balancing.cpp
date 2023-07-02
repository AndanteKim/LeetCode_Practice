typedef long long ll;

class Solution {
private:
    int dfs(int totalMask, vector<int>& balanceList, vector<int>& memo){
        if (memo[totalMask] != -1) return memo[totalMask];
        
        ll balanceSum = 0;
        int ans = 0;
        for (int i = 0; i < 12; ++i){
            int currBit = 1 << i;
            if (totalMask & currBit){
                balanceSum += balanceList[i];
                ans = max(ans, dfs(totalMask ^ currBit, balanceList, memo));
            }
        }
        memo[totalMask] = ans + (balanceSum == 0);
        return memo[totalMask];
    }
    
public:
    int minTransfers(vector<vector<int>>& transactions) {
        vector<int> balanceList(12), memo(1 << 12, -1);
        for (vector<int>& transaction : transactions){
            balanceList[transaction[0]] += transaction[2];
            balanceList[transaction[1]] -= transaction[2];
        }
        memo[0] = 0;
        return 12 - dfs((1 << 12) - 1, balanceList, memo);
    }
};