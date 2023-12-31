class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1, n = s.size();
        unordered_map<char, vector<int>> idxLists;
        
        for (int i = 0; i < n; ++i){
            idxLists[s[i]].push_back(i);
        }
        
        for (auto& [_, indices]: idxLists){
            ans = max(ans, indices.back() - indices[0] - 1);
        }
        
        return ans;
    }
};