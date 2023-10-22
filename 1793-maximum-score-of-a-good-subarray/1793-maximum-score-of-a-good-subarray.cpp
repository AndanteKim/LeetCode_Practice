class Solution {
private:
    int n;
    int solve(vector<int>& nums, int k){
        vector<int> left(k);
        int currMin = INT_MAX;
        for (int i = k - 1; i >= 0; --i){
            currMin = min(currMin, nums[i]);
            left[i] = currMin;
        }
        
        currMin = INT_MAX;
        vector<int> right;
        
        for (int i = k; i < n; ++i){
            currMin = min(currMin, nums[i]);
            right.push_back(currMin);
        }
        int i, ans = 0;
        for (int j = 0; j < right.size(); ++j){
            i = lower_bound(left.begin(), left.end(), right[j]) - left.begin();
            int size = (k + j) - i + 1;
            ans = max(ans, right[j] * size);
        }
        
        return ans;
    }
    
public:
    int maximumScore(vector<int>& nums, int k) {
        this -> n = nums.size();
        int ans = solve(nums, k);
        reverse(nums.begin(), nums.end());
        return max(ans, solve(nums, n - k - 1));
    }
};