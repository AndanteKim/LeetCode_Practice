class Solution {
private:
    int n;
    
    void backtrack(int i, string curr, string& s, vector<string>& ans, unordered_set<string>& words){
        if (i >= n){
            if (i == n) ans.push_back(curr.substr(0, curr.size() - 1));
            return;
        }
        
        for (int j = i + 1; j <= n; ++j){
            string str = s.substr(i, j - i);
            if (words.find(str) != words.end()){
                backtrack(j, curr + str + " ", s, ans, words);
            }
        }
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this -> n = s.size();
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<string> ans;
        
        backtrack(0, "", s, ans, words);
        return ans;
    }
};