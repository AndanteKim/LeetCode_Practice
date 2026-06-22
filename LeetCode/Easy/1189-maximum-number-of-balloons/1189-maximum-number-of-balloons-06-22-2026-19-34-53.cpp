class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;
        for (const auto& c : text) {
            ++freq[c];
        }

        int ans = std::numeric_limits<int>::max();
        for (const char& c : vector<char>{'b', 'a', 'l', 'o', 'n'}) {
            if (c == 'l' || c == 'o') ans = min(ans, freq[c] >> 1);
            else ans = min(ans, freq[c]);
        }

        return ans == std::numeric_limits<int>::max()? 0 : ans;
    }
};