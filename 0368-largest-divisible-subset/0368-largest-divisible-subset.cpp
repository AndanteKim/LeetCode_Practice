class Solution {
private:
    int n;
    vector<int> EDS(int i, vector<vector<int>>& memo, vector<int>& nums){
        if (!memo[i].empty()) return memo[i];
        int tail = nums[i];
        vector<int> maxSubset;
        
        for (int p = 0; p < i; ++p){
            if (tail % nums[p] == 0){
                vector<int> subset = EDS(p, memo, nums);
                if (maxSubset.size() < subset.size()) maxSubset = subset;
            }
        }
        
        maxSubset.push_back(tail);
        return memo[i] = maxSubset;
    }
    
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this -> n = nums.size();
        vector<vector<int>> memo(this -> n);
        vector<int> ans;
        
        for (int i = 0; i < n; ++i){
            vector<int> curr = EDS(i, memo, nums);
            if (curr.size() > ans.size()) ans = curr;
        }
        
        return ans;
    }
};