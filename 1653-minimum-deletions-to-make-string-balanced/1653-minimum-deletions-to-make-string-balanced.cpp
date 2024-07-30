class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), deleteCount = 0;
        stack<int> st;
        
        // Iterate through each character in the string
        for (int i = 0; i < n; ++i){
            // If stack is not empty, top of stack is 'b',
            // current character is 'a'.
            if (!st.empty() && s[st.top()] == 'b' && s[i] == 'a'){
                st.pop();   // Remove 'b' from stack
                ++deleteCount;  // Increment deletion count
            }
            else
                st.push(i);     // Append current character to stack
        }
        
        return deleteCount;
    }
};