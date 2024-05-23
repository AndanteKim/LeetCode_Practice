class Solution {
private:
    int n;
    int countBeautifulSubsets(vector<int>& nums, int diff, int i, int mask){
        // Base case: Return 1 if mask is greater than 0 (non-empty subset)
        if (i == n)
            return (mask > 0)? 1 : 0;
        
        // Flag to check if the current subset is beautiful
        bool isBeautiful = true;
        int take = 0;
        
        // Check if the current number forms a beautiful pair with any previous
        // number in the subset
        for (int j = 0; j < i && isBeautiful; ++j){
            isBeautiful = (((1 << j) & mask) == 0 || abs(nums[j] - nums[i]) != diff);
        }
        
        // Recursively calculate beautiful subsets including and excluding the current number
        if (isBeautiful) take = countBeautifulSubsets(nums, diff, i + 1, mask | (1 << i));
        int skip = countBeautifulSubsets(nums, diff, i + 1, mask);
        return skip + take;
    }
    
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        this -> n = nums.size();
        return countBeautifulSubsets(nums, k, 0, 0);
    }
};