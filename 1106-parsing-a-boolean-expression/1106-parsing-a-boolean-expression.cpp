class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        string ops{"&|!"}, types{"&|!tf"};
        
        // Traverse through the expression
        for (const char& c : expression){
            if (c == ',' || c == '(')
                continue;   // Skip commas and open parentheses
            
            // Push operators and boolean values to the stack
            if (types.find(c) != string::npos)
                st.push(c);
            
            // Handle closing parentheses and evaluate the subexpression
            if (c == ')'){
                bool hasTrue = false, hasFalse = false;
                
                // Process the values inside the parentheses
                while (ops.find(st.top()) == string::npos){
                    if (st.top() == 't')
                        hasTrue = true;
                    
                    if (st.top() == 'f')
                        hasFalse = true;
                    st.pop();
                }
                
                // Pop the operator and evaluate the subexpression
                char op = st.top(); st.pop();
                if (op == '!')
                    st.push(hasTrue? 'f' : 't');
                else if (op == '&')
                    st.push(hasFalse? 'f' : 't');
                else
                    st.push(hasTrue? 't' : 'f');
            }
        }
        
        // The final result is at the top of the stack
        return st.top() == 't';
    }
};