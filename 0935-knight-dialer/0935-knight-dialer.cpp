class Solution {
private:
    unordered_map<int, vector<int>> directions{{0,{4,6}}, {1,{6,8}},\
    {2,{7,9}}, {3,{4,8}}, {4,{0,3,9}}, {5,{}}, {6,{0,1,7}},\
    {7,{2,6}}, {8,{1,3}}, {9,{2,4}}};
    int mod = 1'000'000'007;
    
    int dp(vector<vector<int>>& memo, int prev, int remain){
        if (remain == 0)
            return 1;
        
        if (memo[remain][prev] != -1)
            return memo[remain][prev];
        
        int ways = 0;
        for (int curr : directions[prev])
            ways = (ways + dp(memo, curr, remain - 1)) % mod; 
            
        return memo[remain][prev] = ways;
    }
    
public:
    int knightDialer(int n) {
        vector memo(n, vector<int>(10, -1));
        int ans = 0;
        for (int i = 0; i <= 9; ++i)
            ans = (ans + dp(memo, i, n - 1)) % mod;
        
        return ans;
    }
};