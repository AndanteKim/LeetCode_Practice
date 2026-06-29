class Solution {
private:
    bool check(const string& pattern, string& word) {
        int m = pattern.size(), n = word.size();
        vector<int> pi(m);

        // Generate the prefix array of the pattern
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && pattern[i] != pattern[j]) j = pi[j - 1];

            if (pattern[i] == pattern[j]) ++j;
            pi[i] = j;
        }

        // Using prefix arrays for matching
        for (int i = 0, j = 0; i < n; ++i) {
            while (j > 0 && word[i] != pattern[j]) j = pi[j - 1];

            if (word[i] == pattern[j]) ++j;
            if (j == m) return true;
        }

        return false;
    }

public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;

        for (const string pattern : patterns) {
            if (check(pattern, word)) ++ans;
        }

        return ans;
    }
};