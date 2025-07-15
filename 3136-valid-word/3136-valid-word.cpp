class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;

        bool hasVowels = false, hasConsonants = false;
        string vowels = "aeiou";

        for (char& c : word){
            if (isalpha(c)){
                if (vowels.find(tolower(c)) != string::npos) hasVowels = true;
                else hasConsonants = true;
            }
            else if (!isdigit(c)) return false;
        }

        return hasVowels && hasConsonants;
    }
};