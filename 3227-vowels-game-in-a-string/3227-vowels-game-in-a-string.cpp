class Solution {
public:
    bool doesAliceWin(string s) {
        string vowels = "aeiou";
        for (const char& c : s){
            if (vowels.find(c) != string::npos) return true;
        }
        return false;
    }
};