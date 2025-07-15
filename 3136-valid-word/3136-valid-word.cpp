class Solution {
public:
    bool isValid(string word) {
        // Base case
        if (word.size() < 3) return false;

        bool vowelExist = false, consonantExist = false;
        unordered_set<char> vowels{'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'}, chars(word.begin(), word.end());

        for (const char& c : chars){
            if (!(('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))) return false;
            if (vowels.contains(c)) vowelExist = true;
            else if ((('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) && !vowels.contains(c)) consonantExist = true;
        }


        return vowelExist && consonantExist;
    }
};