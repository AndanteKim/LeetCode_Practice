class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> groups;
        for (int row = nums.size() - 1; row >= 0; --row){
            for (int col = 0; col < nums[row].size(); ++col){
                int diagonals = row + col;
                groups[diagonals].push_back(nums[row][col]);
            }
        }
        
        vector<int> ans;
        for (int curr = 0; curr < groups.size(); ++curr)
            ans.insert(ans.end(), groups[curr].begin(), groups[curr].end());
        
        return ans;
    }
};