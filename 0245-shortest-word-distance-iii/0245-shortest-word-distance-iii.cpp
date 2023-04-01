class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int ans = INT_MAX, prevIndex = -1;
        
        for (int i = 0; i < wordsDict.size(); ++i){
            if (wordsDict[i] == word1 || wordsDict[i] == word2){
                if (prevIndex != -1 && (wordsDict[prevIndex] != wordsDict[i] || word1 == word2)) ans = min(ans, i - prevIndex);
                prevIndex = i;
            }
        }
        
        return ans;
    }
};