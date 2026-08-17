class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector f(n, vector<int>(n));
        vector maxl(n, vector<int>(n)), maxr(n, vector<int>(n));

        for (int left = n - 1; left >= 0; --left) {
            maxl[left][left] = stoneValue[left], maxr[left][left] = stoneValue[left];
            int suml = 0, total = stoneValue[left];
            int i = left - 1;
            for (int right = left + 1; right < n; ++right) {
                total += stoneValue[right];

                while (i + 1 < right && (suml + stoneValue[i + 1]) * 2 <= total) {
                    suml += stoneValue[i++ + 1];
                }

                if (left <= i) f[left][right] = max(f[left][right], maxl[left][i]);

                if (i + 1 < right) f[left][right] = max(f[left][right], maxr[i + 2][right]);

                if (suml * 2 == total) f[left][right] = max(f[left][right], maxr[i + 1][right]);

                maxl[left][right] = max(maxl[left][right - 1], total + f[left][right]);
                maxr[left][right] = max(maxr[left + 1][right], total + f[left][right]);
            }
        }

        return f[0][n - 1];
    }
};