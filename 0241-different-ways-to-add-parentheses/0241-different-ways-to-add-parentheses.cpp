class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        // Initialize memoization for unordered_map
        unordered_map<string, vector<int>> memo;
        
        // Solve for the entire expression
        return computeResult(expression, memo, 0, expression.size() - 1);
    }
    
private:
    vector<int> computeResult(string& expression, unordered_map<string, vector<int>>& memo, int start, int end){
        // If result is already memoized, return it.
        if (memo.count(to_string(start) + " " + to_string(end)))
            return memo[to_string(start) + " " + to_string(end)];
        
        vector<int> ans;
        unordered_map<char, function<int(int, int)>> operations{
            {'+', [](int x, int y) {return x + y;}}, {'-', [](int x, int y) {return x - y;}}, \
            {'*', [](int x, int y) {return x * y;}}
        };
        
        // Base case: single digit
        if (start == end)
            return vector<int>{expression[start] - '0'};
        
        // Base case: two digits
        if (end - start == 1 && isdigit(expression[start]))
            return vector<int>{stoi(expression.substr(start, end - start + 1))};
        
        // Recursive case: split the expression at each operator
        for (int i = start; i <= end; ++i){
            if (isdigit(expression[i])) continue;
            
            vector<int> leftRes = computeResult(expression, memo, start, i - 1);
            vector<int> rightRes = computeResult(expression, memo, i + 1, end);
            
            // Combine results from left and right subexpressions
            for (int leftVal : leftRes){
                for (int rightVal : rightRes){
                   ans.push_back(operations[expression[i]](leftVal, rightVal)); 
                }
            }
        }
        
        // Memoize the result for this subproblem
        return memo[to_string(start) + " " + to_string(end)] = ans;
    }
};