class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int length1 = word1.size(), length2 = word2.size(), i = 0, j = 0;
        
        while (i < length1 || j < length2){
            if (i < length1){
                ans += word1[i];
                ++i;
            }
            
            if (j < length2){
                ans += word2[j];
                ++j;
            }
        }
        
        return ans;
    }
};