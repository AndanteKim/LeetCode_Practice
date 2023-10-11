class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> diff;
        diff[0] = 0;
        for (vector<int>& flower : flowers){
            ++diff[flower[0]];
            --diff[flower[1] + 1];
        }
        
        vector<int> positions, prefix;
        int curr = 0;
        
        for (auto& [key, val] : diff){
            positions.push_back(key);
            curr += val;
            prefix.push_back(curr);
        }
        
        vector<int> ans;
        for (int person : people){
            int i = upper_bound(positions.begin(), positions.end(), person) - positions.begin() - 1;
            ans.push_back(prefix[i]);
        }
        
        return ans;
    }
};