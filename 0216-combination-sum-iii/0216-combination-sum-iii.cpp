class Solution {
private:
    void backtrack(int start, vector<int>& curr, vector<vector<int>>& ans, int length, int remain){
        if (length == 0){
            if (remain == 0) ans.push_back(curr);
            return;
        }
        
        for (int i = start; i <= 9; ++i){
            curr.push_back(i);
            backtrack(i + 1, curr, ans, length - 1, remain - i);
            curr.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(1, curr, ans, k, n);
        
        return ans;
    }
};