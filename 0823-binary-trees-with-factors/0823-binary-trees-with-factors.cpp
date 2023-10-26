class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int MOD = 1'000'000'007, n = arr.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; ++i)
            index[arr[i]] = i;
        
        vector<long> dp(n, 1);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < i; ++j){
                if (arr[i] % arr[j] == 0){
                    int right = arr[i] / arr[j];
                    if (index.find(right) != index.end()){
                        dp[i] = (dp[i] + dp[j] * dp[index[right]]) % MOD;
                    }
                }
            }
        }
        
        return accumulate(dp.begin(), dp.end(), 0L) % MOD;
    }
};