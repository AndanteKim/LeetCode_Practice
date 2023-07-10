class Solution {
private:
    int pascal(int i, int j, map<pair<int, int>, int>& memo){
        if (j == 1 || i == 1 || j == i) return 1;
        
        if (memo.find({i, j}) != memo.end()) return memo[{i, j}];
        
        return memo[{i, j}] = pascal(i - 1, j - 1, memo) + pascal(i, j - 1, memo);
    }
    
public:
    vector<vector<int>> generate(int numRows) {
        map<pair<int, int>, int> memo;
        
        vector<vector<int>> dp;
        for (int j = 1; j < numRows + 1; ++j){
            vector<int> row;
            for (int i = 1; i <= j; ++i) row.push_back(pascal(i, j, memo));
            dp.push_back(row);
        }
        
        return dp;
    }
};