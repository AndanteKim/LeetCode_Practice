class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters(s.begin(), s.end());
        int ans = 0;
        
        for (char letter : letters){
            int i = -1, j = 0;
            
            for (int k = 0; k < s.size(); ++k){
                if (s[k] == letter){
                    if (i == -1)
                        i = k;
                    j = k;
                }
            }
            
            unordered_set<char> between;
            for (int k = i + 1; k < j; ++k){
                between.insert(s[k]);
            }
            
            ans += between.size();
        }
        
        return ans;
    }
};