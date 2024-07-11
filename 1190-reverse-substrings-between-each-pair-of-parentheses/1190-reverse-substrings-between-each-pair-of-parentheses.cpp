class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<int> stk;
        
        for (char& c : s){
            // Store the current length as the start index
            // for future reversal
            if (c == '(')
                stk.push(ans.size());
            else if (c == ')'){
                int start = stk.top(); stk.pop();
                // Reverse the substring between the matching parenthesis
                reverse(ans.begin() + start, ans.end());
            }
            else
                // Append non-parentheses characters to the processed list
                ans.push_back(c);
        }
        
        return ans;
    }
};