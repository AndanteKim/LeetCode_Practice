class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<char> letters;
        string ans;
        for (const char& c:s) if (isalpha(c))
            letters.push_back(c);
        for (const char& c:s){
            if (isalpha(c)){
                ans += letters.back();
                letters.pop_back();
            }
            else ans += c;
        }
        return ans;
    }
};