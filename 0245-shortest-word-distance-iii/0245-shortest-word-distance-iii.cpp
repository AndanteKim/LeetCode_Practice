class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int ans = INT_MAX;
        vector<pair<int, int>> indices;
        
        for (int i = 0; i < wordsDict.size(); ++i){
            if (wordsDict[i] == word1){
                indices.push_back({i, 0});
            }
            
            if (wordsDict[i] == word2){
                indices.push_back({i, 1});
            }
        }
        
        for (int i = 0; i < indices.size() - 1; ++i){
            if (indices[i].second != indices[i + 1].second && indices[i].first != indices[i + 1].first)
                ans = min(ans, indices[i + 1].first - indices[i].first);
        }
        
        return ans;
    }
};