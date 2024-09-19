class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        this -> n = expression.size();
        // Create a 2D array of lists to store results of subproblems
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
        
        initializeBaseCase(expression, dp);
        
        // Fill the dp table for all possible subexpressions
        for (int length = 3; length <= n; ++length){
            for (int start = 0; start <= n - length; ++start){
                int end = start + length - 1;
                processSubexpression(expression, dp, start, end);
            }
        }
        
        // Return the results for the entire expression
        return dp[0][n - 1];
    }
    
private:
    int n;
    void initializeBaseCase(string& expression, vector<vector<vector<int>>>& dp){
        // Handle base cases: single digits and two-digit numbers
        for (int i = 0; i <= n - 1; ++i){
            if (isdigit(expression[i])){
                // Check if it's a two-digit number
                int d1 = expression[i] - '0';
                if (i + 1 < n && isdigit(expression[i + 1])){
                    int d2 = expression[i + 1] - '0';
                    dp[i][i + 1].push_back(d1 * 10 + d2);
                }
            
                // Single digit case
                dp[i][i].push_back(d1);
            }
        }
    }
    
    void processSubexpression(string& expression, vector<vector<vector<int>>>& dp, int start, int end){
        unordered_map<char, function<int(int, int)>> operations {
            {'+', [](int a, int b) {return a + b;}}, {'-', [](int a, int b) {return a - b;}},\
            {'*', [](int a, int b) {return a * b;}}
        };
        // Try all possible positions to split the expression
        for (int split = start; split <= end; ++split){
            if (isdigit(expression[split]))
                continue;
            vector<int> leftRes = dp[start][split - 1], rightRes = dp[split + 1][end];
            
            for (int leftVal : leftRes){
                for (int rightVal : rightRes){
                    dp[start][end].push_back(operations[expression[split]](leftVal, rightVal));
                }
            }
        }
    }
};