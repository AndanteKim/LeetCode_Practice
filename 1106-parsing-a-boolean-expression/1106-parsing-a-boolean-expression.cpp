class Solution {
private:
    char evaluateSubstr(const string& subStr){
        // Extract the operator and the enclosed values
        char op = subStr[0];
        string value = subStr.substr(2, subStr.size() - 3);
        
        // Apply logical operations based on the operator
        if (op == '!')
            return (value[0] == 't')? 'f' : 't';
        
        if (op == '&')
            return (value.find('f') != string::npos)? 'f' : 't';
        
        if (op == '|')
            return (value.find('t') != string::npos)? 't' : 'f';
        
        // This point should never be reached
        return 'f';
    }
    
public:
    bool parseBoolExpr(string expression) {
        // Repeatedly simplify the expression by evaluating subexpressions
        while (expression.size() > 1){
            int start = expression.find_last_of("!&|");
            int end = expression.find(')', start);
            string subStr = expression.substr(start, end - start + 1);
            char res = evaluateSubstr(subStr);
            // Replace with evaluated result
            expression.replace(start, end - start + 1, 1, res);
        }
        
        return expression[0] == 't';
    }
};