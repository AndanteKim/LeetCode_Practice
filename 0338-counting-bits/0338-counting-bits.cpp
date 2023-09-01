class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int x = 1; x <= n; ++x){
            ans[x] = ans[x >> 1] + (x & 1);
        }
        return ans;
    }
};