class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> arithmetic{"+", "-", "*", "/"};
        
        stack<int> stk;
        for (string& token : tokens){
            if (arithmetic.count(token)){
                int second = stk.top();
                stk.pop();
                int first = stk.top(), res;
                stk.pop();
                switch(token[0]){
                    case '+':
                        res = first + second;
                        break;
                    case '-':
                        res = first - second;
                        break;
                    case '*':
                        res = first * second;
                        break;
                    case '/':
                        res = first / second;
                        break;
                } 
                
                stk.push(res);
            }
            else stk.push(stoi(token));
        }
        
        return stk.top();
    }
};