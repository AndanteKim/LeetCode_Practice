class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        unordered_set<int> dups;
        unordered_map<int, int> seen;
        
        for (int i = 0; i < nums.size(); ++i){
            if (!dups.count(nums[i])){
                dups.insert(nums[i]);
                for (int j = i + 1; j < nums.size(); ++j){
                    int complement = -(nums[i] + nums[j]);
                    if (seen.count(complement) && seen[complement] == i){
                        vector<int> triplet = {nums[i], nums[j], complement};
                        sort(triplet.begin(), triplet.end());
                        ans.insert(triplet);
                    }
                    seen[nums[j]] = i;
                }
            }
            
        }
        
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};