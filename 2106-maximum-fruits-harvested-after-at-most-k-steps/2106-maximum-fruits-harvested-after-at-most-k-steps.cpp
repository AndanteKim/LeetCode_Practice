class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> prefixSum(n + 1), indices(n);

        for (int i = 0; i < n; ++i){
            prefixSum[i + 1] = prefixSum[i] + fruits[i][1];
            indices[i] = fruits[i][0];
        }

        int ans = 0, y;
        for (int x = 0; x <= (k >> 1); ++x){
            y = k - 2 * x;

            // Move left x steps, then move right k - x steps.
            int left = startPos - x, right = startPos + y;
            int start = lower_bound(indices.begin(), indices.end(), left) - indices.begin(), end = upper_bound(indices.begin(), indices.end(), right) - indices.begin();
            ans = max(ans, prefixSum[end] - prefixSum[start]);

            // Move right x steps, then left k - x steps.
            left = startPos - y, right = startPos + x;
            start = lower_bound(indices.begin(), indices.end(), left) - indices.begin(), end = upper_bound(indices.begin(), indices.end(), right) - indices.begin();
            ans = max(ans, prefixSum[end] - prefixSum[start]);
        }
        
        return ans;
    }
};