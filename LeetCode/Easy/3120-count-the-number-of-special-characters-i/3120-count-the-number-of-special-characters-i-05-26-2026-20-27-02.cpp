class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> chars;

        for (const char& c : word)
            chars.insert(c);
        
        int ans = 0;
        for (const char& c : chars) {
            if (chars.contains(c - 32) || chars.contains(c + 32)) ++ans;
        }

        return ans >> 1;
    }
};