class Solution {
private:
    int n1, n2, n3;
    
    bool dp(string& s1, int i, string& s2, int j, string& s3, int k, vector<vector<int>>& memo){
        if (i == n1) return s2.substr(j) == s3.substr(k);
        if (j == n2) return s1.substr(i) == s3.substr(k);
        if (memo[i][j] >= 0) return memo[i][j]? true : false;
        
        bool ans = false;
        if ((s1[i] == s3[k] && dp(s1, i + 1, s2, j, s3, k + 1, memo)) || (s2[j] == s3[k] && dp(s1, i, s2, j + 1, s3, k + 1, memo)))
            ans = true;
        
        return memo[i][j] = ans? 1 : 0;
    }
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        this -> n1 = s1.size(), this -> n2 = s2.size(), this -> n3 = s3.size();
        vector<vector<int>> memo(n1, vector<int>(n2, -1));
        if (n1 + n2 != n3) return false;
        
        return dp(s1, 0, s2, 0, s3, 0, memo);
    }
};