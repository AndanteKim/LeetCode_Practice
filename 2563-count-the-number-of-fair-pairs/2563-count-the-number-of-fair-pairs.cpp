typedef long long ll;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        ll ans = 0;
        for (int i = 0; i < nums.size(); ++i){
            // Assume we've picked nums[i] as the first pair element.
            
            // 'low' indicates the number of possible pairs with sum < lower.
            int low = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            
            // 'high' indicates the number of possible pairs with sum <= upper
            int high = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            
            // Their difference gives the number of elements with sum in the given range. 
            ans += high - low;
        }
        
        return ans;
    }
};