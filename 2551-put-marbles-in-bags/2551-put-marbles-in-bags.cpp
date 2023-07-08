typedef long long ll;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        ll ans = 0;
        vector<ll> pairWeights(n - 1);
        
        for (int i = 0; i < n - 1; ++i) pairWeights[i] = weights[i] + weights[i + 1];
        sort(pairWeights.begin(), pairWeights.end());
        for (int i = 0; i < k - 1; ++i){
            ans += pairWeights[n - 2 - i] - pairWeights[i];
        }
        
        return ans;
    }
};