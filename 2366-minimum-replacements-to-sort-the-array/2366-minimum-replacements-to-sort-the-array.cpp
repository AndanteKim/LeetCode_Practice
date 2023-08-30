typedef long long ll; 

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        ll ans = 0;
        int n = nums.size();
        
        for (int i = n - 2; i >= 0; --i){
            // No need to break if they're in order
            if (nums[i] <= nums[i + 1]) continue;
            
            // count how many elements are made from breaking nums[i]
            int numElements = (nums[i] + nums[i + 1] - 1) / nums[i + 1];
            
            // It requires numElements - 1 replacement operations
            ans += numElements - 1;
            
            // maximize nums[i] after replacement
            nums[i] /= numElements;
        }
        
        return ans;
    }
};