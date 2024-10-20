class Solution {
public:
    bool parseBoolExpr(string expression) {
        int index = 0;
        return evaluate(expression, index);
    }
    
private:
    // Recursively parse and evaluate the boolean expression
    bool evaluate(const string& expr, int& index){
        char ch = expr[index++];
        
        // Base case: true ('t') or false ('f')
        if (ch == 't') return true;
        if (ch == 'f') return false;
        
        // Handle NOT operation '!(...)'
        if (ch == '!'){
            ++index;    // Skip '('
            bool result = !evaluate(expr, index);
            ++index;    // Skip ')'
            return result;
        }
        
        // Handle AND '&(...)' and OR '|(...)'
        vector<bool> values;
        ++index;    // Skip '('
        while (expr[index] != ')'){
            if (expr[index] != ',')
                values.push_back(evaluate(expr, index));    // Collect results of subexpressions
            else
                ++index;    // Skip commas
        }
        ++index;            // Skip ')'
        
        // Manual AND operation: returns false if any value is false
        if (ch == '&')
            return count(values.begin(), values.end(), false) == 0;
        
        // Manual OR operation: returns true if any value is true
        if (ch == '|')
            return count(values.begin(), values.end(), true) > 0;
        
        // This point should never be reached.
        return false;
    }
    
};