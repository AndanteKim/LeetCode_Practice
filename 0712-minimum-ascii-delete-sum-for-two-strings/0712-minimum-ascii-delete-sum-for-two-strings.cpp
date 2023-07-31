class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        if (s1.size() < s2.size()) return minimumDeleteSum(s2, s1);
        
        int m = s1.size(), n = s2.size(), ans = 0;
        vector<int> currRow(n + 1, 0);
        
        for (int j = 1; j <= n; ++j) currRow[j] = currRow[j - 1] + s2[j - 1];
        
        for (int i = 1; i <= m; ++i){
            int diagonal = currRow[0];
            currRow[0] += s1[i - 1];
            
            for (int j = 1; j <= n; ++j){
                if (s1[i - 1] == s2[j - 1]) ans = diagonal;
                else ans = min(s1[i - 1] + currRow[j], s2[j - 1] + currRow[j - 1]);
                diagonal = currRow[j];
                currRow[j] = ans;
            }
        }
        
        return currRow.back();
    }
};