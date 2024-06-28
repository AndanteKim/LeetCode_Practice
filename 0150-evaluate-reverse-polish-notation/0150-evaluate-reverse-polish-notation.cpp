class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> ops{
            {"+", [](int a, int b){return a + b;}},
            {"-", [](int a, int b){return a - b;}},
            {"*", [](int a, int b){return a * b;}},
            {"/", [](int a, int b){return a / b;}}
        };
        unordered_set<string> arithmetic{"+", "-", "*", "/"};
        
        stack<int> stk;
        for (string& token : tokens){
            if (arithmetic.count(token)){
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                
                stk.push(ops[token](first, second));
            }
            else stk.push(stoi(token));
        }
        
        return stk.top();
    }
};