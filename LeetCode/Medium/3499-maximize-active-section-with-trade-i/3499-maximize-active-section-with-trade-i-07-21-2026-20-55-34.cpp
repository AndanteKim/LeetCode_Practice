class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int cnt1 = count(s.begin(), s.end(), '1'), n = s.size();
        vector<int> zeroBlocks;
        int i = 0;

        while (i < n) {
            int start = i;

            while (i < n && s[i] == s[start]) {
                ++i;
            }

            if (s[start] == '0') zeroBlocks.push_back(i - start);
        }

        int ans = 0, m = zeroBlocks.size();

        if (m < 2) return cnt1;

        for (int i = 0; i < m - 1; ++i) {
            ans = max(ans, zeroBlocks[i] + zeroBlocks[i + 1]);
        }
        
        return cnt1 + ans;
    }
};