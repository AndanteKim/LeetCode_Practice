#define ll long long

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int ans = 0;
        ll prefix_sum = 0;
        for (int i = 0; i < nums.size(); ++i){
            prefix_sum += nums[i];
            int curr = ceil((double)prefix_sum / (i + 1));
            ans = max(ans, curr);
        }
        return ans;
    }
};