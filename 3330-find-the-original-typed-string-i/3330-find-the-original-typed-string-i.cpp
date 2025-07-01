class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1, n = word.size();

        for (int i = 1; i < n; ++i) if (word[i - 1] == word[i]) ++ans;

        return ans;
    }
};