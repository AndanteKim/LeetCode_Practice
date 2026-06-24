class Solution {
private:
    static constexpr long long MOD = 1'000'000'007;
    using Matrix = vector<vector<long long>>;

    Matrix mul(const Matrix& a, const Matrix& b) {
        int n = a.size(), m = b[0].size();
        Matrix ans(n, vector<long long>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < a[0].size(); ++k) {
                long long r = a[i][k];
                if (r == 0) continue;
                
                for (int j = 0; j < m; ++j) ans[i][j] = (ans[i][j] + r * b[k][j]) % MOD;
            }
        }

        return ans;
    }

    Matrix powMul(Matrix base, long long exp, Matrix ans) {
        while (exp > 0) {
            if (exp & 1) ans = mul(ans, base);
            base = mul(base, base);
            exp >>= 1;
        }

        return ans;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (n == 1) return m;

        int size = 2 * m;
        Matrix u(size, vector<long long>(size, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < i; ++j) u[i][j + m] = 1;

            for (int j = i + 1; j < m; ++j) u[i + m][j] = 1;
        }

        Matrix dp(1, vector<long long>(size, 1));

        dp = powMul(move(u), n - 1, move(dp));

        long long ans = 0;

        for (int i = 0; i < size; ++i) {
            ans = (ans + dp[0][i]) % MOD;
        }

        return ans;
    }
};