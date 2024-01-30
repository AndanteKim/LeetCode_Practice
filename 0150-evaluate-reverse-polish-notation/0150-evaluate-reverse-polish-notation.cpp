class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        int ans;
        unordered_set<string> ops4{"+", "-", "*", "/"};
        
        for (string& token:tokens){
            if (ops4.find(token) != ops4.end()){
                int second = stoi(s.top());
                s.pop();
                int first = stoi(s.top()), ops = 0;
                s.pop();
                
                if (token == "+")
                    ops += first + second;
                else if (token == "-")
                    ops += first - second;
                else if (token == "*")
                    ops += first * second;
                else
                    ops += first / second;
                s.push(to_string(ops));
            }
            else{
                s.push(token);
            }
        }
        ans = stoi(s.top());
        return ans;
    }
};