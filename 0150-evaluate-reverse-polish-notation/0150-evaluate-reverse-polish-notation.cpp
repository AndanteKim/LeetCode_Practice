class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> operations;
        operations["+"] = [](int a, int b){return a + b;};
        operations["-"] = [](int a, int b){return a - b;};
        operations["*"] = [](int a, int b){return a * b;};
        operations["/"] = [](int a, int b){return a / b;};
        
        stack<int> st;
        for (string& token:tokens){
            if (operations.find(token) != operations.end()){
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();
                st.push(operations[token](n1, n2));
            }
            else
                st.push(stoi(token));
        }
        
        return st.top();
    }
};