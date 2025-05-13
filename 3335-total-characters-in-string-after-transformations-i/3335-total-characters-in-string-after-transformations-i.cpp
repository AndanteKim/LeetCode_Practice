class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1'000'000'007;
        vector<int> cnt(26, 0);

        for (const char& c: s)
            ++cnt[c - 97];

        for (int i = 0; i < t; ++i){
            vector<int> nxt(26, 0);
            nxt[0] = cnt[25];
            nxt[1] = (cnt[25] + cnt[0]) % mod;

            for (int j = 2; j < 26; ++j)
                nxt[j] = cnt[j - 1];
            cnt = nxt;
        }

        int ans = accumulate(cnt.begin(), cnt.end(), 0LL) % mod;
        return ans;
    }
};