class Solution {
public:
    int numSub(string s) {
        int n = s.size(), count1 = 0;
        long long ans = 0;
        const int mod = 1'000'000'007;

        for (const char& c : s) {
            if (c == '1') ++count1;
            else {
                ans = (ans + ((long long)count1 * (count1 + 1) >> 1)) % mod;
                count1 = 0;
            }
        }

        if (count1 > 0) ans = (ans + ((long long)count1 * (count1 + 1) >> 1)) % mod;

        return static_cast<int>(ans);
    }
};