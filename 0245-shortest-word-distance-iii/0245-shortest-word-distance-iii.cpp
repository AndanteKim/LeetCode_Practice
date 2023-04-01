class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int ans = INT_MAX;
        vector<int> w1_loc, w2_loc;
        
        for (int i = 0; i < wordsDict.size(); ++i){
            if (wordsDict[i] == word1){
                w1_loc.push_back(i);
            }
            
            if (!w1_loc.empty() && !w2_loc.empty() && w1_loc.back() != w2_loc.back()){
                ans = min(ans, abs(w1_loc.back() - w2_loc.back()));
            }
            
            if (wordsDict[i] == word2){
                w2_loc.push_back(i);
            }
            
        }
        
        if (w1_loc.back() != w2_loc.back()) ans = min(ans, abs(w1_loc.back() - w2_loc.back()));
        
        return ans;
    }
};