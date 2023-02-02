class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        unordered_map<string, set<string>> wordToSimilarWords;
        
        for (const vector<string>& p : similarPairs){
            wordToSimilarWords[p[0]].insert(p[1]);
            wordToSimilarWords[p[1]].insert(p[0]);
        }
        
        for (int i = 0; i < sentence1.size(); ++i){
            if (sentence1[i] == sentence2[i] || wordToSimilarWords[sentence1[i]].find(sentence2[i]) != wordToSimilarWords[sentence1[i]].end()) 
                continue;
            return false;
        }
        return true;
    }
};