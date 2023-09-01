class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; ++i){
            int k = i;
            
            while (k > 0){
                ans[i] += k & 1;
                k >>= 1;
            }
        }
        
        return ans;
    }
};