class Solution {
private:
    int n;
    int longestPairChain(int i, vector<vector<int>>& pairs, vector<int>& memo){
        if (memo[i]) return memo[i];
        
        memo[i] = 1;
        for (int j = i + 1; j < n; ++j){
            if (pairs[i][1] < pairs[j][0])
                memo[i] = max(memo[i], 1 + longestPairChain(j, pairs, memo));
        }
        
        return memo[i];
    }
    
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        this -> n = pairs.size();
        int ans = 0;
        vector<int> memo(n);
        sort(pairs.begin(), pairs.end());
        
        for (int i = 0; i < n; ++i){
            ans = max(ans, longestPairChain(i, pairs, memo));
        }
        
        return ans;
    }
};