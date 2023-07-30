class Solution {
private:
    int n;
    int solve(int left, int right, string& s, vector<vector<int>>& memo){
        if (memo[left][right] != -1) return memo[left][right];
        
        memo[left][right] = n;
        int j = -1;
        for (int i = left; i < right; ++i){
            if (s[i] != s[right] && j == -1) j = i;
            if (j != -1) memo[left][right] = min(memo[left][right], 1 + solve(j, i, s, memo) + solve(i + 1, right, s, memo));
        }
        if (j == -1) memo[left][right] = 0;
        return memo[left][right];
    }
    
public:
    int strangePrinter(string s) {
        this -> n = s.size();
        vector memo(n, vector<int>(n, -1));
        return solve(0, n - 1, s, memo) + 1;
    }
};