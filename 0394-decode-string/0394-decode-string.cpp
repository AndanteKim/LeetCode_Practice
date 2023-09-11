class Solution {
public:
    string decodeString(string s) {
        stack<char> stack;
        int n = s.size();
        
        for (int i = 0; i < n; ++i){
            if (s[i] == ']'){
                string decodedString = "";
                // get the encoded string
                while (stack.top() != '['){
                    decodedString += stack.top();
                    stack.pop();
                }
                
                // pop [ from stack
                stack.pop();
                int num = 0, base = 1;
                while (!stack.empty() && isdigit(stack.top())){
                    num += (stack.top() - '0') * base;
                    base *= 10;
                    stack.pop();
                }
                
                // decode k[decodeString] by pushing decodedString k time into stack
                while (num > 0){
                    for (int j = decodedString.size() - 1; j >= 0; --j){
                        stack.push(decodedString[j]);
                    }
                    --num;
                }
            }
            
            // push the current character to stack
            else{
                stack.push(s[i]);
            }
        }
        
        // get the result from stack
        string ans = "";
        for (int i = stack.size() - 1; i >= 0; --i){
            ans = stack.top() + ans;
            stack.pop();
        }
        return ans;
    }
};