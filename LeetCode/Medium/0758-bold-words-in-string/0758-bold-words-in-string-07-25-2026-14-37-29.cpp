class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        int n = s.size();
        vector<bool> mask(n, false);

        for (int i = 0; i < n; ++i) {
            for (const string& word : words) {
                bool isMatch = true;

                for (int k = 0; k < word.size(); ++k) {
                    if (k + 1 >= s.size() || s[k + i] != word[k]) {
                        isMatch = false;
                        break;
                    }
                }

                if (isMatch) {
                    for (int j = i; j < i + word.size(); ++j) mask[j] = true;
                }
            }
        }

        string ans = "";
        for (int i = 0; i < n; ++i) {
            if (mask[i] && (i == 0 || !mask[i - 1])) ans += "<b>";
            ans += s[i];
            if (mask[i] && (i == n - 1 || !mask[i + 1])) ans += "</b>";
        }

        return ans;
    }
};