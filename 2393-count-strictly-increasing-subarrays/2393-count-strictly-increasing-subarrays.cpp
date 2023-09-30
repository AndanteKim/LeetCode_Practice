typedef long long ll;

class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        // Greedy algorithm
        int n = nums.size(); 
        ll ans = 0, count = 0;
        
        for (int i = 0; i < n; ++i){
            count = 1;
            while (i + 1 < n && nums[i] < nums[i + 1]){
                ++count;
                ++i;
            }
            ans += ((count + 1) * count) / 2;
        }
        
        return ans;
    }
};