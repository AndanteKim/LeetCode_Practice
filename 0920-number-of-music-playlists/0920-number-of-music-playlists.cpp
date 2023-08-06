typedef long long ll;

class Solution {
private:
    int MOD = 1'000'000'007, n, k;
    ll numberOfPlaylists(int i, int j, vector<vector<ll>>& memo){
        if (i == 0 && j == 0) return 1;
        if (i == 0 || j == 0) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        
        memo[i][j] = (numberOfPlaylists(i - 1, j - 1, memo) * (n - j + 1)) % MOD;
        if (j > k) memo[i][j] = (memo[i][j] + numberOfPlaylists(i - 1,j, memo) * (j - k)) % MOD; 
        return memo[i][j];
    }
    
public:
    int numMusicPlaylists(int n, int goal, int k) {
        this -> n = n, this -> k = k;
        vector<vector<ll>> memo(goal + 1, vector<ll>(n + 1, -1));
        return numberOfPlaylists(goal, n, memo);
    }
};