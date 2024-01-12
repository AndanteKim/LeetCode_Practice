class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cntA = 0, cntB = 0;
        string a = s.substr(0, s.size() / 2), b = s.substr(s.size() / 2);
        
        for (int i = 0; i < a.size(); ++i){
            if (vowels.find(a[i]) != vowels.end())
                ++cntA;
        }
        
        for (int i = 0; i < b.size(); ++i){
            if (vowels.find(b[i]) != vowels.end())
                ++cntB;
        }
        
        return cntA == cntB;
    }
};