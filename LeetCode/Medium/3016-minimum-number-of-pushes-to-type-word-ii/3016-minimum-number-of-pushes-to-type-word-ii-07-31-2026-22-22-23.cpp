class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);

        for (const auto& c : word) {
            ++freq[c - 'a'];
        }

        sort(freq.begin(), freq.end(), [](int a, int b) { return a > b;});

        int ans = 0, push = 0;

        for (int i = 0; i < 26; ++i) {
            ans += (freq[i] * (push++ / 8 + 1));
        }

        return ans;
    }
};