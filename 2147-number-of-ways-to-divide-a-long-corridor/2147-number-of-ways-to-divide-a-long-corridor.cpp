class Solution {
private:
    int n, MOD = 1'000'000'007;
    int count(int i, int seats, vector<vector<int>>& memo, string& corridor){
        if (i == n)
            return seats == 2? 1:0;
        if (memo[i][seats] != -1)
            return memo[i][seats];
        
        int ans = 0;
        if (seats == 2){
            if (corridor[i] == 'S')
                ans = count(i + 1, 1, memo, corridor);
            else
                ans = (count(i + 1, 0, memo, corridor) + count(i + 1, 2, memo, corridor)) % MOD;
        }
        else{
            if (corridor[i] == 'S')
                ans = count(i + 1, seats + 1, memo, corridor);
            else
                ans = count(i + 1, seats, memo, corridor);
        }
        
        return memo[i][seats] = ans;
    }
    
public:
    int numberOfWays(string corridor) {
        n = corridor.size();
        vector memo(n, vector<int>(3, -1));
        return count(0, 0, memo, corridor);
    }
};