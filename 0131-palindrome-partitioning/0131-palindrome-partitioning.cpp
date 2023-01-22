class Solution {
public:
    void dfs(vector<vector<string>> &answer, string &s, int start, vector<string> &currentList, vector<vector<bool>> &dp){
        if (start >= s.size()) answer.push_back(currentList);
        for (int end = start; end < s.size(); ++end){
            if(s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])){
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(answer, s, end + 1, currentList, dp);
                currentList.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool> (len, false));
        vector<vector<string>> answer;
        vector<string> currentList;
        dfs(answer, s, 0, currentList, dp);
        return answer;
    }
};