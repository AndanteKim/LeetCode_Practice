class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1, ans = 0;
        
        while (i >= 0 && s[i] == ' ') --i;
        
        while (i >= 0 && ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))){
            ++ans;
            --i;
        }
            
        return ans;
    }
};