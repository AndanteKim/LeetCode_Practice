class Solution {
private:
    int n;
    void backtrack(int i, string curr, vector<string>& ans){
        // Base case
        if (i == n) {
            ans.push_back(curr);
            return;
        }

        for (const char& c : vector<char>{'a','b','c'}){
            if (curr.empty() || curr.back() != c)
                backtrack(i + 1, curr + c, ans);
        }
    }

public:
    string getHappyString(int n, int k) {
        this -> n = n;
        vector<string> ans;
        backtrack(0, "", ans);
        return k <= ans.size()? ans[k - 1] : ""; 
    }
};