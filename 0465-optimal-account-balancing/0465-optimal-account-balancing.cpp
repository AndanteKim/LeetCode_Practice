class Solution {
private:
    int n = 12;
    int dfs(int curr, vector<int>& balanceMap){
        while (curr < n && !balanceMap[curr]) ++curr;
        if (curr == n) return 0;
        
        int cost = INT_MAX;
        for (int next = curr + 1; next < n; ++next){
            if (balanceMap[next] * balanceMap[curr] < 0){
                balanceMap[next] += balanceMap[curr];
                cost = min(cost, 1 + dfs(curr + 1, balanceMap));
                balanceMap[next] -= balanceMap[curr];
            }
        }
        return cost;
    }
    
public:
    int minTransfers(vector<vector<int>>& transactions) {
        vector<int> balanceMap(12);
        for (vector<int>& transaction : transactions){
            balanceMap[transaction[0]] += transaction[2];
            balanceMap[transaction[1]] -= transaction[2];
        }
        
        return dfs(0, balanceMap);
    }
};