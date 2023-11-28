class Solution {
public:
    int numberOfWays(string corridor) {
        const int n = corridor.size(), MOD = 1e9 + 7;
        vector<int> indices;
        
        for (int i = 0; i < n; ++i){
            if (corridor[i] == 'S')
                indices.push_back(i);
        }
        
        // When division is not possible
        if (indices.empty() || indices.size() % 2 == 1)
            return 0;
        
        // Total number of ways
        long count = 1;
        int prevFirstLast = 1, currSecondFirst = 2;
        
        // Take the product of non-paired neighbors
        while (currSecondFirst < indices.size()){
            count = (count * (indices[currSecondFirst] - indices[prevFirstLast])) % MOD;
            prevFirstLast += 2;
            currSecondFirst += 2;
        }
        
        return count;
    }
};