class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> prev(n + 1, -1);

        for (int i = 0; i < n; ++i) {
            if (i == 0 || s[i - 1] == '0') prev[i + 1] = i;
            else prev[i + 1] = prev[i];
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int j = i, cnt0 = s[i - 1] == '0'? 1 : 0;

            while (j > 0 && cnt0 * cnt0 <= n) {
                int cnt1 = (i - prev[j]) - cnt0;
                if (cnt0 * cnt0 <= cnt1)
                    ans += min(j - prev[j], cnt1 - cnt0 * cnt0 + 1); 
                j = prev[j];
                ++cnt0;
            }
        }

        return ans;
    }
};