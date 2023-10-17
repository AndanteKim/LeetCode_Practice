class Solution {
private:
    int dp(vector<vector<int>>& memo, string& word1, string& word2, int i, int j){
        if (i == 0)
            return j;
        if (j == 0)
            return i;
        
        if (memo[i][j] != -1)
            return memo[i][j];
        
        int operations = 0;
        if (word1[i - 1] == word2[j - 1]){
            operations = dp(memo, word1, word2, i - 1, j - 1);
        }
        else{
            int insertion = 1 + dp(memo, word1, word2, i - 1, j);
            int deletion = 1 + dp(memo, word1, word2, i, j - 1);
            int replace = 1 + dp(memo, word1, word2, i - 1, j - 1);
            operations = min(insertion, min(deletion, replace));
        }
        return memo[i][j] = operations;
    }
    
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector memo(m + 1, vector<int>(n + 1, -1));
        return dp(memo, word1, word2, word1.size(), word2.size());
    }
};