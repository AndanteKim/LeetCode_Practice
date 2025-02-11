class Solution {
private:
    // Helper function to check if the top of the stack matches the 'part'
    bool checkMatch(stack<char>& st, string& part, int partLength){
        stack<char> temp = st;

        // Iterate through part from right to left
        for (int partIndex = partLength - 1; partIndex >= 0; --partIndex){
            // If current stack top doesn't match expected character
            if (temp.top() != part[partIndex])
                return false;
            temp.pop();
        }

        return true;
    }

public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int strLength = s.size(), partLength = part.size();

        // Iterate through each character in the string
        for (int index = 0; index < strLength; ++index){
            // Push current character to stack
            st.push(s[index]);

            // If stack size is greater than or equal to the part length, check for match
            if (st.size() >= partLength && checkMatch(st, part, partLength)){
                // Pop the characters matching 'part' from the stack
                for (int j = 0; j < partLength; ++j) st.pop();
            }
        }

        // Convert stack to string with correct order
        string ans = "";

        while (!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};