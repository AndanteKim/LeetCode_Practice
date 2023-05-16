class Solution {
private:
    int n, k;
    vector<vector<int>> costs;
    unordered_map<string, int> memo;
    
    int memoSolve(int houseNumber, int color){
        
        if (houseNumber == n - 1) return costs[houseNumber][color];
        if (memo.find(getKey(houseNumber, color)) != memo.end()) return memo[getKey(houseNumber, color)];
        
        int minRemainingCost = INT_MAX;
        for (int nextColor = 0; nextColor < k; ++nextColor){
            if (color == nextColor) continue;
            int currentRemainingCost = memoSolve(houseNumber + 1, nextColor);
            minRemainingCost = min(currentRemainingCost, minRemainingCost);
        }
        
        int totalCost = costs[houseNumber][color] + minRemainingCost;
        memo[getKey(houseNumber, color)] = totalCost;
        return totalCost;
    }
    
    string getKey(int n, int color){
        string ans = to_string(n) + ' ' + to_string(color);
        return ans;
    }
    
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;
        k = costs[0].size(), n = costs.size();
        this -> costs = costs;
        int minCost = INT_MAX;
        for (int color = 0; color < k; ++color) minCost = min(minCost, memoSolve(0, color));
        
        return minCost;
    }
};