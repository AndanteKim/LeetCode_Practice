class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        unordered_map<int, int> freq;
        for (int c : candies) ++freq[c];

        int windows = 0;
        for (int i = 0; i < k; ++i) {
            --freq[candies[i]];
            if (freq[candies[i]] == 0) ++windows;
        }

        int ans = freq.size() - windows;
        for (int i = k; i < candies.size(); ++i) {
            ++freq[candies[i - k]];
            if (freq[candies[i - k]] == 1) --windows;

            --freq[candies[i]];
            if (freq[candies[i]] == 0) ++windows;

            ans = max(ans, (int)freq.size() - windows);
        }

        return ans;
    }
};