class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "", stack = "";
        int n = pattern.size();

        // Iterate through the pattern
        for (int index = 0; index <= n; ++index){
            // Push the next number onto the stack
            stack.push_back((char)(index + 49));

            // If 'I' is encountered or we reach the end, pop all stack elements
            if (index == n || pattern[index] == 'I'){
                while (!stack.empty()){
                    ans.push_back(stack.back());
                    stack.pop_back();
                }
            }
        }

        return ans;
    }
};