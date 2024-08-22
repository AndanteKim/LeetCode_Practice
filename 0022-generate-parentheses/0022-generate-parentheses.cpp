class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return vector<string>{""};
        
        vector<string> ans;
        for (int leftCount = 0; leftCount < n; ++leftCount){
            for (const string& leftString : generateParenthesis(leftCount)){
                for (const string& rightString : generateParenthesis(n - 1 - leftCount)){
                    ans.push_back("(" + leftString + ")" + rightString);
                }
            }
        }
        
        return ans;
    }
};