class Solution {
private:
    string mapping(vector<int>& nums){
        string temp = "";
        
        for (int num : nums){
            // distinguish for each number to do not conflict one another i.e. [1, 11], [11, 1]
            temp += to_string(num) + "$";
        }
        
        return temp;
    }
    
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size();
        unordered_map<string, int> mp;
        
        // mapping with the help of map function which convert rows in unique strings
        for (int i = 0; i < n; ++i){
            ++mp[mapping(grid[i])];
        }
        
        for (int i = 0; i < n; ++i){
            string search = "";
            for (int j = 0; j < n; ++j){
                search += to_string(grid[j][i]) + "$";
            }
            ans += mp[search];
             
        }
        
        return ans;
    }
};