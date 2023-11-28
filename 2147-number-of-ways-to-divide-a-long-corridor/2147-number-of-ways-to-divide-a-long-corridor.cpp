class Solution {
public:
    int numberOfWays(string corridor) {
        const int n = corridor.size(), MOD = 1e9 + 7;
        vector<vector<int>> count(n + 1, vector<int>(3));
        count[n][2] = 1;
        
        for (int i = n - 1; i >= 0; --i){
            if (corridor[i] == 'S'){
                count[i][0] = count[i + 1][1];
                count[i][1] = count[i + 1][2];
                count[i][2] = count[i + 1][1];
            }
            else{
                count[i][0] = count[i + 1][0];
                count[i][1] = count[i + 1][1];
                count[i][2] = (count[i + 1][0] + count[i + 1][2]) % MOD;
            }
        }
        
        return count[0][0];
    }
};