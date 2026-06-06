typedef long long ll;

class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        auto solve = [&](ll num) -> ll {
            if (num < 100) return 0;

            string s = to_string(num);
            int n = s.size();

            ll memoCnt[16][10][10];
            ll memoSum[16][10][10];
            memset(memoCnt, -1, sizeof(memoCnt));
            memset(memoSum, -1, sizeof(memoSum));

            auto dfs = [&](this auto&& dfs, int pos, int prev, int curr,
                           bool isLim, bool isLead) -> pair<ll, ll> {
                if (pos == n) return {1, 0};

                if (!isLim && !isLead && prev >= 0 && curr >= 0) {
                    if (memoCnt[pos][prev][curr] != -1) {
                        return {memoCnt[pos][prev][curr], memoSum[pos][prev][curr]};
                    }
                }

                ll cnt = 0, sum = 0;
                int up = isLim? s[pos] - '0' : 9;
                for (int digit = 0; digit <= up; ++digit) {
                    bool newLead = isLead && (digit == 0);
                    
                    int newPrev = curr, newCurr = newLead? -1 : digit;
                    auto [subCnt, subSum] = dfs(pos + 1, newPrev, newCurr, isLim && (digit == up), newLead);

                    if (!newLead && prev >= 0 && curr >= 0) {
                        if ((prev < curr && curr > digit) || (prev > curr && curr < digit)) sum += subCnt;
                    }

                    cnt += subCnt;
                    sum += subSum;
                }

                if (!isLim && !isLead && prev >= 0 && curr >= 0) {
                    memoCnt[pos][prev][curr] = cnt;
                    memoSum[pos][prev][curr] = sum;
                }

                return {cnt, sum};
            };

            auto [_, totalSum] = dfs(0, -1, -1, true, true);
            return totalSum;
        };

        return solve(num2) - solve(num1 - 1);
    }
};