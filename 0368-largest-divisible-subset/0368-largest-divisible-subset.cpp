class Solution {
private:
    int n;
    vector<int> dp(int i, unordered_map<int, vector<int>>& memo, vector<int>& nums){
        if (memo.count(i))
            return memo[i];

        vector<int> maxSubset;
        int tail = nums[i];

        // The value of EDS(i) depends on it previous elements
        for (int p = 0; p < i; ++p){
            if (tail % nums[p] == 0){
                vector<int> subset = dp(p, memo, nums);
                if (maxSubset.size() < subset.size()) maxSubset = subset;
            }
        }

        // Extend the found max subset with the current tail.
        maxSubset.push_back(tail);

        // Memorize the intermediate solutions for reuse.
        return memo[i] = maxSubset;
    }


public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Base case
        if (nums.size() == 0) return {};

        sort(nums.begin(), nums.end());
        this -> n = nums.size();
        vector<int> ans;
        unordered_map<int, vector<int>> memo;

        // Find the largest divisible subset
        for (int i = 0; i < n; ++i){
            vector<int> subset = dp(i, memo, nums);
            if (ans.size() < subset.size())
                ans = subset;
        }

        return ans;
    }
};