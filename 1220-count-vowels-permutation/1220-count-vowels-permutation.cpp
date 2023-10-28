class Solution {
public:
    int countVowelPermutation(int n) {
        vector permutations(5, vector<long>(n, 1));
        int MOD = 1'000'000'007, ans = 0;
        
        for (int i = 1; i < n; ++i){
            // a
            permutations[0][i] = (permutations[1][i - 1] + permutations[2][i - 1] + permutations[4][i - 1]) % MOD;
            // e
            permutations[1][i] = (permutations[0][i - 1] + permutations[2][i - 1]) % MOD;
            // i
            permutations[2][i] = (permutations[1][i - 1] + permutations[3][i - 1]) % MOD;
            // o
            permutations[3][i] = permutations[2][i - 1] % MOD;
            // u
            permutations[4][i] = (permutations[2][i - 1] + permutations[3][i - 1]) % MOD;
        }
        
        for (int i = 0; i < 5; ++i) ans = (ans + permutations[i].back()) % MOD;
        
        return ans;
    }
};