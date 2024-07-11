class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> pairs(n);
        stack<int> openParenthesesIndices;
        
        // First pass: Pair up parentheses
        for (int i = 0; i < n; ++i){
            if (s[i] == '('){
                openParenthesesIndices.push(i);
            }
            else if (s[i] == ')'){
                int j = openParenthesesIndices.top();
                openParenthesesIndices.pop();
                pairs[i] = j;
                pairs[j] = i;
            }
        }
        
        // Second pass: Build the string ans
        int currIndex = 0, direction = 1;
        string ans = "";
        
        while (currIndex < n){
            if (s[currIndex] == '(' || s[currIndex] == ')'){
                currIndex = pairs[currIndex];
                direction *= -1;
            }
            else
                ans.push_back(s[currIndex]);
            
            currIndex += direction;
        }
        
        return ans;
    }
};