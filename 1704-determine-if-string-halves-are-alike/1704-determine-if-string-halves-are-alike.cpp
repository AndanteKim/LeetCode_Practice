class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size(), aVowelCount = 0;
        string vowels = "aeiouAEIOU";
        
        for (int i = 0; i < n / 2; ++i){
            if (vowels.find(s[i]) != string::npos)
                ++aVowelCount;
        }
        
        int bVowelCount = 0;
        for (int i = n / 2; i < n; ++i){
            if (vowels.find(s[i]) != string::npos)
                ++bVowelCount;
        }
        
        return aVowelCount == bVowelCount;
    }
};