class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        
        // Traverse the entire expression
        for (const char& ch : expression){
            if (ch == ')'){
                vector<char> values;
                
                // Gather all values inside the parentheses
                while (st.top() != '('){
                    values.push_back(st.top());
                    st.pop();   
                }
                st.pop();   // Remove '('
                char op = st.top();
                st.pop();   // Remove the operator
                
                // Evaluate the subexpression and push the result back
                char res = evalSubExpr(op, values);
                st.push(res);
            }
            else if (ch != ',')
                // Push non-comma characters into the stack
                st.push(ch);
        }
        
        // Final result is on the top of the stack
        return st.top() == 't';
    }
    
private:
    // Evaluates a subexpression based on the operator and list of values
    char evalSubExpr(const char& op, const vector<char>& values){
        if (op == '!')
            return (values[0] == 't')? 'f' : 't';
        
        // AND: return 'f' if any value is 'f', otherwise return 't'
        if (op == '&'){
            for (const char& val : values)
                if (val == 'f') return 'f';
            return 't';
        }
        
        // OR: return 't' if any value is 't', otherwise return 'f'
        if (op == '|'){
            for (const char& val : values)
                if (val == 't') return 't';
            return 'f';
        }
            
        // This point should never be reached
        return 'f';
    }
};