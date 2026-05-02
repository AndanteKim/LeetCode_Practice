class Solution {
public:
    int rotatedDigits(int n) {
        string s = to_string(n);
        int k = s.size();

        vector memo(k + 1, vector<vector<int>>(2, vector<int>(2, 0)));
        memo[k][0][1] = memo[k][1][1] = 1;

        for (int i = k - 1; i >= 0; --i) {
            for (int eqf = 0; eqf <= 1; ++eqf) {
                for (int invf = 0; invf <= 1; ++invf) {
                    int ans = 0;
                    char lim = (eqf == 1)? s[i] : '9';

                    for (char d = '0'; d <= lim; ++d) {
                        if (d == '3' || d == '4' || d == '7') continue;
                    
                        bool invo = (d == '2' || d == '5' || d == '6' || d == '9');
                        int nextEqf = (d == s[i])? eqf : 0;
                        int nextInvf = invo? 1 : invf;

                        ans += memo[i + 1][nextEqf][nextInvf];
                    }
                    memo[i][eqf][invf] = ans;
                }
            }
        }

        return memo[0][1][0];
    }
};