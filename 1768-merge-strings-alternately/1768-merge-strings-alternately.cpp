class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, len1 = word1.size(), j = 0, len2 = word2.size();
        string ans = "";
        while (i < len1 || j < len2){
            if (i < len1){
                ans += word1[i];
                ++i;
            }
            if (j < len2){
                ans += word2[j];
                ++j;
            }
        }
        
        return ans;
    }
};