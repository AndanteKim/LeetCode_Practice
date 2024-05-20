class Solution {
private:
    int n;
    
    void generateSubsets(vector<int>& nums, int i, vector<int> subset, vector<vector<int>>& subsets){
        // Base case: index reached end of nums
        // Add the current subset to subsets
        if (i == n){
            subsets.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        // Generate subsets with nums[i]
        generateSubsets(nums, i + 1, subset, subsets);
        subset.pop_back();
        // Generate subsets without nums[i]
        generateSubsets(nums, i + 1, subset, subsets);
        
    }
    
public:
    int subsetXORSum(vector<int>& nums) {
        this -> n = nums.size();
        vector<vector<int>> subsets;
        // Generate all of the subsets
        generateSubsets(nums, 0, {}, subsets);
        int ans = 0;
        
        // Compute the XOR total for each subset and add to the result
        for (auto& subset:subsets){
            int xorTotal = 0;
            for (int num : subset){
                xorTotal ^= num;
            }
            ans += xorTotal;
        }
        
        return ans;
    }
};