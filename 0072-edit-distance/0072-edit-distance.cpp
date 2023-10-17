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
            int insertion = dp(memo, word1, word2, i - 1, j);
            int deletion = dp(memo, word1, word2, i, j - 1);
            int replace = dp(memo, word1, word2, i - 1, j - 1);
            operations = min(insertion, min(deletion, replace)) + 1;
        }
        return memo[i][j] = operations;
    }
    
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector memo(m + 1, vector<int>(n + 1, -1));
        return dp(memo, word1, word2, m, n);
    }
};