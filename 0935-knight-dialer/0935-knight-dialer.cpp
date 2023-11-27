class Solution {
private:
    int MOD = 1'000'000'007;
    vector<vector<long>> multiply(vector<vector<long>>& A, vector<vector<long>>& B){
        vector<vector<long>> res(A.size(), vector<long>(B[0].size()));
        for (int i = 0; i < A.size(); ++i){
            for (int j = 0; j < B[0].size(); ++j){
                for (int k = 0; k < B.size(); ++k){
                    res[i][j] = (res[i][j] + (A[i][k] * B[k][j])) % MOD;
                }
            }
        }
        return res;
    }
    
public:
    int knightDialer(int n) {
        if (n == 1)
            return 10;
        
        vector<vector<long>> A = {
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}
        };
        
        --n;
        vector<vector<long>> v{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
        while (n > 0){
            if (n & 1)
                v = multiply(v, A);
            
            A = multiply(A, A);
            n >>= 1;
        }
        
        return (accumulate(v[0].begin(), v[0].end(), 0L) % MOD);
    }
};