typedef long long ll;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int C = m + n - 2, r = m - 1;
        ll ans = 1;
        
        for (int i = 1; i <= r; ++i){
            ans = ans * (C - r + i) / i;
        }
        return ans;
    }
};