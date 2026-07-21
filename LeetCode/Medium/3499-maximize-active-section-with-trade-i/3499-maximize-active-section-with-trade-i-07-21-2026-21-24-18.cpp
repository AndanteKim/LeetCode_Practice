class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int cnt1 = count(s.begin(), s.end(), '1'), n = s.size();
        int i = 0, prev = std::numeric_limits<int>::min();
        int ans = 0;

        while (i < n){
            int start = i;
            while (i < n && s[i] == s[start]) ++i;

            if (s[start] == '0') {
                int curr = i - start;
                ans = max(ans, prev + curr);
                prev = curr;
            }
        }

        return cnt1 + ans;
    }
};