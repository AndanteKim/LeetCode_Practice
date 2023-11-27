class Solution {
public:
    int knightDialer(int n) {
        if (n == 1)
            return 10;
        
        int A = 4, B = 2, C = 2, D = 1, MOD = 1'000'000'007;
        
        for (int i = 0; i < n - 1; ++i){
            int tempA = A;
            A = ((2 * B) % MOD + (2 * C) % MOD) % MOD;
            B = tempA;
            int tempC = C;
            C = (tempA + (2 * D) % MOD) % MOD;
            D = tempC;
        }
        
        int ans = 0;
        ans = (A + B) % MOD;
        ans = (ans + C) % MOD;
        
        return (ans + D) % MOD;
    }
};