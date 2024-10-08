class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int mismatched = 0;
        
        for (const char& c : s){
            // If an opening bracket is encountered, push it in the stack
            if (c == '[')
                st.push(c);
            else{
                // If the stack is not empty, then pop it.
                if (!st.empty()) st.pop();
                
                // Otherwise, increment the mismatched
                else ++mismatched;
            }
        }
        
        return (mismatched + 1) >> 1;
    }
};