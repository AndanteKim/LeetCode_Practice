class Solution {
private:
    int n;
    void backtrack(vector<int>& curr, unordered_map<int, int>& counter, vector<vector<int>>& ans){
        if (curr.size() == n){
            ans.push_back(curr);
            return;
        }
        
        for (auto& [key, val] : counter){
            if (val > 0){
                curr.push_back(key);
                --val;
                backtrack(curr, counter, ans);
                curr.pop_back();
                ++val;
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        unordered_map<int, int> counter;
        vector<int> curr;
        vector<vector<int>> ans;
        for (int num : nums) ++counter[num];
        
        backtrack(curr, counter, ans);
        
        return ans;
    }
};