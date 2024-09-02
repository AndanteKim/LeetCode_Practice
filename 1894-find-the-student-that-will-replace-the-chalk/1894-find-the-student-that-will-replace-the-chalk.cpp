class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        if (chalk.empty())
            return 0;
        
        int remain = k, n = chalk.size();
        vector<long> prefixSum(n + 1);
        
        for (int i = 1; i <= n; ++i)
            prefixSum[i] = prefixSum[i - 1] + chalk[i - 1];
        
        remain %= prefixSum.back();
        for (int i = 0; i <= n; ++i)
            if (0 <= remain && remain < prefixSum[i])
                return i - 1;
        
        return -1;
    }
};