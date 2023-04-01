class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int ans = INT_MAX;
        vector<int> w1_loc, w2_loc;
        
        for (int i = 0; i < wordsDict.size(); ++i){
            if (wordsDict[i] == word1){
                w1_loc.push_back(i);
            }
            
            if (wordsDict[i] == word2){
                w2_loc.push_back(i);
            }
        }
        
        for (int index : w1_loc){
            int x = upper_bound(w2_loc.begin(), w2_loc.end(), index) - w2_loc.begin();
            
            if (x != w2_loc.size()) ans = min(ans, w2_loc[x] - index);
            if (x != 0 && w2_loc[x - 1] != index)
                ans = min(ans, index - w2_loc[x - 1]);
            
        }
        
        
        return ans;
    }
};