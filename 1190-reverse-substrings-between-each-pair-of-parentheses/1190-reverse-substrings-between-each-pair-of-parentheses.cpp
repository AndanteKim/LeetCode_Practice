class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        
        for (char& c : s){
            if (c == ')'){
                string curr = "";
                while (!stk.empty() && stk.top() != "("){
                    curr.append(stk.top()); stk.pop();
                }
                
                if (!stk.empty() && stk.top() == "(")
                    stk.pop();
                reverse(curr.begin(), curr.end());
                stk.push(curr);
            }
            else stk.push(string(1, c));
        }
        
        string ans = "";
        while (!stk.empty()){
            ans.append(stk.top());
            stk.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};