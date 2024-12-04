class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str2.size(), j = 0;
        
        for (const char& c : str1){
            if ((0 <= str2[j] - c && str2[j] - c <= 1) || (c - str2[j]) == 25)
                ++j;
            
            if (j >= m)
                return true;
        }
        
        return false;
    }
};