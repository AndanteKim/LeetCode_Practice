class Solution {
private:
    int n, MOD = 1'000'000'007;
    long dp(int node, set<int>& arrSet, unordered_map<int, int>& memo){
        long ans = 1;
        if (memo.find(node) != memo.end()) return memo[node];
        
        for (int num : arrSet){
            if (node % num == 0 && arrSet.find(node / num) != arrSet.end()){
                ans = (ans + (dp(num, arrSet, memo) * dp(node / num, arrSet, memo)));
                ans %= MOD;
            }
        }
        return memo[node] = ans;
    }
    
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        this -> n = arr.size();
        unordered_map<int, int> memo;
        set<int> arrSet(arr.begin(), arr.end());
        long ans = 0;
        for (int num : arrSet){
            ans += dp(num, arrSet, memo);
            ans %= MOD;
        }
        
        return ans;
    }
};