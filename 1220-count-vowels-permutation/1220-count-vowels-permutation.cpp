class Solution {
private:
    int n, MOD = 1'000'000'007;
    // 0: 'a', 1: 'e', 2: 'i', 3: 'o', 4: 'u'
    map<int, set<int>> followUp{{0, {1}},\
                                  {1, {0, 2}},\
                                  {2, {0, 1, 3, 4}},\
                                  {3, {2, 4}},\
                                  {4, {0}}
                                 };
    
    int dp(int remain, int prev, vector<vector<int>>& memo){
        if (remain == 0)
            return 1;
        
        if (memo[remain][prev] != -1)
            return memo[remain][prev];
        
        int ways = 0;
        for (int ch : followUp[prev]){
            ways = (ways + dp(remain - 1, ch, memo)) % MOD;
        }
        
        return memo[remain][prev] = ways;
    }
    
public:
    int countVowelPermutation(int n) {
        this -> n = n;
        vector memo(n, vector<int>(5, -1));
        int ans = 0;
        // 0: 'a', 1: 'e', 2: 'i', 3: 'o', 4: 'u'
        for (int i = 0; i < 5; ++i)
            ans = (ans + dp(n - 1, i, memo)) % MOD;
        
        return ans;
    }
};