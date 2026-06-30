class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        if (n < 3) return 0;

        int ans = 0, left = 0;
        unordered_map<char, int> freq;

        for (int right = 0; right < n; ++right) {
            ++freq[s[right]];

            while (freq['a'] >= 1 && freq['b'] >= 1 && freq['c'] >= 1) {
                ans += n - right;
                --freq[s[left++]];
            }
        }

        return ans;
    }
};