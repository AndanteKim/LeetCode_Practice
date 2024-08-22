class Solution {
private:
    int n;
    void backtrack(vector<string>& ans, int i, string curr, int balance){
        if (i == n * 2){
            if (balance == 0)
                ans.push_back(curr);
            return;
        }
        if (balance < 0)
            return;
        
        backtrack(ans, i + 1, curr + "(", balance + 1);
        backtrack(ans, i + 1, curr + ")", balance - 1);
    }
    
public:
    vector<string> generateParenthesis(int n) {
        this -> n = n;
        vector<string> ans;
        backtrack(ans, 0, "", 0);
        
        return ans;
    }
};