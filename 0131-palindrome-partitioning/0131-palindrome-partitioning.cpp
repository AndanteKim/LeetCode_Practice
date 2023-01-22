class Solution {
public:
    bool isPalindrome(string &s, int low, int high){
        while (low < high){
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
    
    void dfs(vector<vector<string>> &answer, string &s, int start, vector<string>& currentList){
        if (start >= s.size()) answer.push_back(currentList);
        
        for (int end = start; end < s.size(); ++end){
            if (isPalindrome(s, start, end)){
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(answer, s, end + 1, currentList);
                currentList.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string> currentList;
        dfs(answer, s, 0, currentList);
        
        return answer;
    }
};