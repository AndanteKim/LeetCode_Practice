class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> m;
        int n = groupSizes.size();
        
        for (int i = 0; i < n; ++i){
            m[groupSizes[i]].push_back(i);
        }
        
        
        vector<vector<int>> ans;
        for (auto& [size, indices] : m){
            vector<int> curr;
            for (int index: indices){
                if (curr.size() < size)
                    curr.push_back(index);
                else{
                    ans.push_back(curr);
                    curr.clear();
                    curr.push_back(index);
                }
            }
            
            if (!curr.empty()) {
                ans.push_back(curr);
                curr.clear();
            }
        }
        
        return ans;
    }
};