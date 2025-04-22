class Solution {
private:
    const int MOD = 1'000'000'007, MAX_N = pow(10, 4) + 10, MAX_P = 15;
    vector<int> sieves;

public:
    int idealArrays(int n, int maxValue) {
        sieves.resize(MAX_N);
        for (int i = 2; i < MAX_N; ++i){
            if (sieves[i] == 0){
                for (int j = i; j < MAX_N; j += i)
                    sieves[j] = i;
            }
        }

        vector<vector<int>> ps(MAX_N);
        
        for (int i = 2; i < MAX_N; ++i){
            int x = i;
            while (x > 1){
                int p = sieves[x], count = 0;
                while (x % p == 0){
                    x /= p;
                    ++count;
                }
                ps[i].push_back(count);
            }
        }

        vector<vector<int>> c(MAX_N + MAX_P, vector<int>(MAX_P + 1, 0));
        c[0][0] = 1;

        for (int i = 1; i < MAX_N + MAX_P; ++i){
            c[i][0] = 1;
            
            for (int j = 1; j <= min(i, MAX_P); ++j){
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
            }
        }

        int ans = 0;

        for (int x = 1; x <= maxValue; ++x){
            long mul = 1;
            for (int p : ps[x]){
                mul = (mul * c[n + p - 1][p]) % MOD;
            }
            ans = (ans + mul) % MOD;
        }

        return ans;
    }
};