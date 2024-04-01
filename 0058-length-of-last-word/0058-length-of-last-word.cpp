class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1, ans = 0;
        bool countStart = false;
        
        while (i >= 0){
            if (!countStart && s[i] == ' '){
                --i;
                continue;
            }
            
            if (countStart && s[i] == ' ') break;
            countStart = true;
            ++ans;
            --i;
        }
        
        return ans;
    }
};