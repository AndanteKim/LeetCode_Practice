typedef long long ll;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<map<ll, int>> count(n);
        
        for (int i = 1; i < n; ++i){
            for (int j = 0; j < i; ++j){
                ll delta = (ll)nums[i] - (ll)nums[j];
                int total = 0;
                if (count[j].find(delta) != count[j].end()){
                    total = count[j][delta];
                }
                count[i][delta] += total + 1;
                ans += total;
            }
        }
        
        return (int)ans;
    }
};