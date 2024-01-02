class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mapping;
        vector<vector<int>> ans;
        
        for (int num: nums)
            ++mapping[num];
        
        for (auto& [num, height]: mapping){
            for (int i = 0; i < height; ++i){
                if (ans.size() <= i)
                    ans.push_back({num});
                else
                    ans[i].push_back(num);
            }
        }
        
        return ans;
    }
};