class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        // Base case: If the expression is empty, return an empty list.
        if (expression.empty()) return {};
        
        // Base case: If the string is a single character, treat it as a number and
        // return it.
        if (expression.size() == 1 || (expression.size() == 2 && isdigit(expression[0])))
            return vector<int>{stoi(expression)};
        
        // If the string has only two characters and the first character is a
        // digit, parse it as a number.
        vector<int> ans;
        int n = expression.size();
        unordered_map<char, function<int(int, int)>> operations{
            {'+', [](int a, int b){return a + b;}}, {'-', [](int a, int b){return a - b;}}, \
            {'*', [](int a, int b){return a * b;}}
        };
        
        // Recursive case: Iterate through each character
        for (int i = 0; i < n; ++i){
            char curr = expression[i];
            
            // Skip if the current character is a digit
            if (isdigit(curr))
                continue;
            
            // Split the expression into left and right parts
            vector<int> leftRes = diffWaysToCompute(expression.substr(0, i));
            vector<int> rightRes = diffWaysToCompute(expression.substr(i + 1));
            
            // Combine results from left and right parts
            for (int leftVal : leftRes){
                for (int rightVal : rightRes){
                    // Perform the operation based on the current character.
                    ans.push_back(operations[curr](leftVal, rightVal));
                }
            }
        }
        
        return ans;
    }
};