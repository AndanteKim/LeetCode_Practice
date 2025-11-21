class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0, n = s.size();
        unordered_set<char> letters(s.begin(), s.end());

        for (const char& letter : letters) {
            int i = s.find(letter), j = s.rfind(letter);

            unordered_set<char> between;
            for (int k = i + 1; k < j; ++k) {
                between.insert(s[k]);
            }

            ans += between.size();
        }

        return ans;
    }
};